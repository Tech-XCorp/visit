// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <QvisRecentPathRemovalWindow.h>
#include <QGroupBox>
#include <QLayout>
#include <QListWidget>
#include <QPushButton>

#include <algorithm>

#include <FileServerList.h>

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::QvisRecentPathRemovalWindow
//
// Purpose:
//   Constructor for the QvisRecentPathRemovalWindow class.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:03:20 PST 2003
//
// Modifications:
//   Brad Whitlock, Wed Apr  9 10:43:50 PDT 2008
//   Make captionString use QString.
//
// ****************************************************************************

QvisRecentPathRemovalWindow::QvisRecentPathRemovalWindow(Subject *s,
    const QString &captionString) : QvisDelayedWindowObserver(s, captionString),
    paths()
{
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::~QvisRecentPathRemovalWindow
//
// Purpose:
//   Destructor for QvisRecentPathRemovalWindow class.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:08:32 PST 2003
//
// Modifications:
//
// ****************************************************************************

QvisRecentPathRemovalWindow::~QvisRecentPathRemovalWindow()
{
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::CreateWindowContents
//
// Purpose:
//   Creates the widgets for the window.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:08:50 PST 2003
//
// Modifications:
//   Brad Whitlock, Tue Apr  8 15:26:49 PDT 2008
//   Support for internationalization.
//
//   Cyrus Harrison, Wed Jun 25 16:13:05 PDT 2008
//   Initial Qt4 Port.
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::CreateWindowContents()
{
    // Create the widgets needed to remove the paths.
    removalControlsGroup = new QGroupBox(central);
    removalControlsGroup->setTitle(tr("Select paths to remove"));
    topLayout->addWidget(removalControlsGroup, 5);

    QVBoxLayout *innerTopLayout = new QVBoxLayout(removalControlsGroup);

    // Create the listbox that lets us select the paths to remove.
    removalListBox = new QListWidget(removalControlsGroup);
    removalListBox->setSelectionMode(QAbstractItemView::MultiSelection);
    innerTopLayout->addWidget(removalListBox);

    // Create the pushbuttons that actually call the removal routines.
    QHBoxLayout *hLayout = new QHBoxLayout();
    innerTopLayout->addLayout(hLayout);
    hLayout->setSpacing(5);
    removeButton = new QPushButton(tr("Remove"), removalControlsGroup);
    connect(removeButton, SIGNAL(clicked()),
            this, SLOT(removePaths()));
    hLayout->addWidget(removeButton);
    removeAllButton = new QPushButton(tr("Remove all"), removalControlsGroup);
    connect(removeAllButton, SIGNAL(clicked()),
            this, SLOT(removeAllPaths()));
    hLayout->addWidget(removeAllButton);
    invertSelectionButton = new QPushButton(tr("Invert selection"), removalControlsGroup);
    connect(invertSelectionButton, SIGNAL(clicked()),
            this, SLOT(invertSelection()));
    hLayout->addWidget(invertSelectionButton);

    // Create the ok and cancel buttons.
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    topLayout->addLayout(buttonLayout);
    buttonLayout->addStretch(10);
    okButton = new QPushButton(tr("Ok"), central);
    connect(okButton, SIGNAL(clicked()),
            this, SLOT(applyDismiss()));
    buttonLayout->addWidget(okButton);
    cancelButton = new QPushButton(tr("Cancel"), central);
    connect(cancelButton, SIGNAL(clicked()),
            this, SLOT(handleCancel()));
    buttonLayout->addWidget(cancelButton);
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::UpdateWindow
//
// Purpose:
//   This method gets called when the window must be updated.
//
// Arguments:
//   doAll : Whether we should unconditionally updated the window.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:09:12 PST 2003
//
// Modifications:
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::UpdateWindow(bool doAll)
{
    if(fileServer->HostChanged() || fileServer->PathChanged() || doAll)
    {
        // Clear out the paths vector.
        paths.clear();

        // Display the file paths for all of the hosts.
        stringVector hosts(fileServer->GetRecentHosts());
        for(size_t i = 0; i < hosts.size(); ++i)
        {
            const stringVector &p = fileServer->GetRecentPaths(hosts[i]);
            for(size_t j = 0; j < p.size(); ++j)
                paths.push_back(QualifiedFilename(hosts[i], p[j], "a"));
        }

        // Make sure the paths are sorted.
        std::sort(paths.begin(), paths.end());

        // Update the window's widgets.
        UpdateWidgets();
    }
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::UpdateWidgets
//
// Purpose:
//   Updates the widgets in the window.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:09:56 PST 2003
//
// Modifications:
//   Cyrus Harrison, Wed Jun 25 16:13:05 PDT 2008
//   Initial Qt4 Port.
//
//   Kathleen Biagas, Thu Jan 21, 2021
//   Replace QString.asprintf with QString.arg.
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::UpdateWidgets()
{
    // Clear the list box.
    removalListBox->clear();

    // Display the file paths for all of the hosts.
    for(size_t i = 0; i < paths.size(); ++i)
    {
        QString f = QString("%1:%2").arg(paths[i].host.c_str()).arg(paths[i].path.c_str());
        removalListBox->addItem(f);
    }

    // Don't enable the removal buttons unless there are paths.
    bool havePaths = (removalListBox->count() > 0);
    removeButton->setEnabled(havePaths);
    removeAllButton->setEnabled(havePaths);
    invertSelectionButton->setEnabled(havePaths);
}

//
// Qt slot functions
//

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::show
//
// Purpose:
//   Forces the window to update when it is shown.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:41:26 PST 2003
//
// Modifications:
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::show()
{
    QvisDelayedWindowObserver::show();
    UpdateWindow(true);
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::removePaths
//
// Purpose:
//   This is a Qt slot function that is called when we want to remove selected
//   paths from the list.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:10:14 PST 2003
//
// Modifications:
//   Cyrus Harrison, Wed Jun 25 16:13:05 PDT 2008
//   Initial Qt4 Port.
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::removePaths()
{
    QualifiedFilenameVector newPaths;
    for(int i = 0; i < removalListBox->count(); ++i)
    {
        if(!removalListBox->item(i)->isSelected())
            newPaths.push_back(paths[i]);
    }
    paths = newPaths;

    UpdateWidgets();
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::removeAllPaths
//
// Purpose:
//   This is a Qt slot function that is called when we want to remove all
//   paths from the list.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:10:14 PST 2003
//
// Modifications:
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::removeAllPaths()
{
    paths.clear();
    UpdateWidgets();
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::invertSelection
//
// Purpose:
//   This is a Qt slot function that is called when we want to invert the
//   selection for the selected paths.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:10:14 PST 2003
//
// Modifications:
//   Cyrus Harrison, Wed Jun 25 16:13:05 PDT 2008
//   Initial Qt4 Port.
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::invertSelection()
{
    for(int i=0;i<removalListBox->count();i++)
    {
        if(removalListBox->item(i)->isSelected())
            removalListBox->item(i)->setSelected(false);
        else
            removalListBox->item(i)->setSelected(true);
    }
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::applyDismiss
//
// Purpose:
//   This is a Qt slot function that is called when we want to remove selected
//   paths from the list.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:10:14 PST 2003
//
// Modifications:
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::applyDismiss()
{
    // Clear out the recent path list.
    fileServer->ClearRecentPathList();
    for(size_t i = 0; i < paths.size(); ++i)
    {
        fileServer->AddPathToRecentList(paths[i].host, paths[i].path);
    }

    // Update the other observers.
    SetUpdate(false);
    fileServer->Notify();

    // Hide the window.
    hide();
}

// ****************************************************************************
// Method: QvisRecentPathRemovalWindow::handleCancel
//
// Purpose:
//   Cancels everything and hides the window.
//
// Programmer: Brad Whitlock
// Creation:   Fri Oct 10 16:13:43 PST 2003
//
// Modifications:
//
// ****************************************************************************

void
QvisRecentPathRemovalWindow::handleCancel()
{
    hide();
}
