// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef QVISREVOLVEWINDOW_H
#define QVISREVOLVEWINDOW_H

#include <QvisOperatorWindow.h>
#include <AttributeSubject.h>

class RevolveAttributes;
class QLabel;
class QCheckBox;
class QLineEdit;
class QButtonGroup;

// ****************************************************************************
// Class: QvisRevolveWindow
//
// Purpose:
//    Defines QvisRevolveWindow class.
//
// Notes:      Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class QvisRevolveWindow : public QvisOperatorWindow
{
    Q_OBJECT
  public:
    QvisRevolveWindow(const int type,
                         RevolveAttributes *subj,
                         const QString &caption = QString::null,
                         const QString &shortName = QString::null,
                         QvisNotepadArea *notepad = 0);
    virtual ~QvisRevolveWindow();
    virtual void CreateWindowContents();
  protected:
    void UpdateWindow(bool doAll);
    virtual void GetCurrentValues(int which_widget);
  private slots:
    void meshTypeChanged(int val);
    void autoAxisChanged(bool val);
    void axisProcessText();
    void startAngleProcessText();
    void stopAngleProcessText();
    void stepsProcessText();
  private:
    QButtonGroup *meshType;
    QCheckBox *autoAxis;
    QLineEdit *axis;
    QLineEdit *startAngle;
    QLineEdit *stopAngle;
    QLineEdit *steps;
    QLabel *meshTypeLabel;
    QLabel *axisLabel;
    QLabel *startAngleLabel;
    QLabel *stopAngleLabel;
    QLabel *stepsLabel;

    RevolveAttributes *atts;
};



#endif
