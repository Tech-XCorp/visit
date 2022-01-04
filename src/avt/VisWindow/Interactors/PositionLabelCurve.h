// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                               PositionLabelCurve.h                        //
// ************************************************************************* //

#ifndef POSITION_LABEL_CURVE_H
#define POSITION_LABEL_CURVE_H
#include <viswindow_exports.h>


#include <VisitInteractor.h>


class VisWindowInteractorProxy;
class vtkPolyData;
class vtkPolyDataMapper2D;
class vtkActor2D;

// ****************************************************************************
//  Class: PositionLabelCurve
//
//  Purpose:
//      Defines what Visit's Curve Navigation interactions should look like,
//      with display of current mouse coordinates.
//
// ****************************************************************************

class VISWINDOW_API PositionLabelCurve : public VisitInteractor
{
  public:
                          PositionLabelCurve(VisWindowInteractorProxy &);
    virtual               ~PositionLabelCurve();

    virtual void          OnTimer(void);

    virtual void          StartLeftButtonAction();
    virtual void          EndLeftButtonAction();
    virtual void          StartMiddleButtonAction();
    virtual void          EndMiddleButtonAction();
    virtual void          OnMouseWheelForward();
    virtual void          OnMouseWheelBackward();
    virtual void          OnMouseMove();

  protected:
    double                canvasDeviceMinX, canvasDeviceMaxX;
    double                canvasDeviceMinY, canvasDeviceMaxY;

    vtkPolyData           *positionLabel;
    vtkPolyDataMapper2D   *positionLabelMapper;
    vtkActor2D            *positionLabelActor;

    void                  SetCanvasViewport(void);
    bool                  AreCoordsInViewport(int &, int &);

  private:
    void                  PanCamera(const int x, const int y);
    void                  ZoomCamera(const int x, const int y);
    void                ZoomCamera(double);
};


#endif


