// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef QVISMULTICURVEPLOTWINDOW_H
#define QVISMULTICURVEPLOTWINDOW_H

#include <QvisPostableWindowObserver.h>
#include <AttributeSubject.h>

class MultiCurveAttributes;
class QButtonGroup;
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QvisColorButton;
class QvisColorManagerWidget;
class QvisLineWidthWidget;
class QvisOpacitySlider;

// ****************************************************************************
// Class: QvisMultiCurvePlotWindow
//
// Purpose:
//    Defines QvisMultiCurvePlotWindow class.
//
// Notes:      Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   Eric Brugger, Wed Jan 21 08:20:18 PST 2009
//   I added yAxisTitleFormat, useYAxisRange, and yAxisRange.  I changed
//   markerVariable from a variable button to a text field.
//   
//   Eric Brugger, Wed Feb 18 07:56:29 PST 2009
//   I added displayIds and idVariable.
//
//   Eric Brugger, Fri Feb 20 16:13:15 PST 2009
//   I added displayLegend.
//
//   Eric Brugger, Thu Mar  5 17:46:26 PST 2009
//   I replaced useYAxisRange and yAxisRange with useYAxisTickSpacing and
//   yAxisTickSpacing.
//
//   Eric Brugger, Fri Feb 15 16:27:14 PST 2013
//   I added markerScale and markerLineWidth.
//
// ****************************************************************************

class QvisMultiCurvePlotWindow : public QvisPostableWindowObserver
{
    Q_OBJECT
  public:
    QvisMultiCurvePlotWindow(const int type,
                         MultiCurveAttributes *subj,
                         const QString &caption = QString::null,
                         const QString &shortName = QString::null,
                         QvisNotepadArea *notepad = 0);
    virtual ~QvisMultiCurvePlotWindow();
    virtual void CreateWindowContents();
  public slots:
    virtual void apply();
    virtual void makeDefault();
    virtual void reset();
  protected:
    void UpdateWindow(bool doAll);
    void GetCurrentValues(int which_widget);
    void Apply(bool ignore = false);

    bool UpdateMultipleAreaColors();
  private slots:
    void colorModeChanged(int index);
    void singleColorChanged(const QColor &color);
    void singleColorOpacityChanged(int opacity);
    void multipleColorChanged(const QColor &color, int index);
    void opacityChanged(int opacity, int index);
    void lineWidthChanged(int style);
    void yAxisTitleFormatProcessText();
    void useYAxisTickSpacingChanged(bool val);
    void yAxisTickSpacingProcessText();
    void displayMarkersChanged(bool val);
    void markerScaleProcessText();
    void markerLineWidthChanged(int style);
    void markerVariableProcessText();
    void displayIdsChanged(bool val);
    void idVariableProcessText();
    void displayLegendChanged(bool val);
  private:
    int                     plotType;
    QGroupBox              *curveColorGroup;
    QButtonGroup           *colorModeButtons;
    QvisColorButton        *singleColor;
    QvisOpacitySlider      *singleColorOpacity;
    QvisColorManagerWidget *multipleColors;
    QvisLineWidthWidget    *lineWidth;
    QLineEdit              *yAxisTitleFormat;
    QCheckBox              *useYAxisTickSpacing;
    QLineEdit              *yAxisTickSpacing;
    QCheckBox              *displayMarkers;
    QLineEdit              *markerVariable;
    QLineEdit              *markerScale;
    QvisLineWidthWidget    *markerLineWidth;
    QCheckBox              *displayIds;
    QLineEdit              *idVariable;
    QCheckBox              *displayLegend;
    QLabel                 *lineWidthLabel;
    QLabel                 *yAxisTitleFormatLabel;
    QLabel                 *markerScaleLabel;
    QLabel                 *markerLineWidthLabel;
    QLabel                 *markerVariableLabel;
    QLabel                 *idVariableLabel;

    MultiCurveAttributes   *atts;
};



#endif
