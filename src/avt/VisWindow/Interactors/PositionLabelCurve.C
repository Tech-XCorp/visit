// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                                PositionLabelCurve.C                               //
// ************************************************************************* //

#include <PositionLabelCurve.h>

#include <VisWindow.h>
#include <VisWindowInteractorProxy.h>

#include <vtkActor2D.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper2D.h>
#include <vtkProperty2D.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

// ****************************************************************************
//  Method: PositionLabelCurve constructor
//
// ****************************************************************************

PositionLabelCurve::PositionLabelCurve(VisWindowInteractorProxy &v) : VisitInteractor(v)
{
  positionLabel = vtkPolyData::New();

  vtkPoints *pts = vtkPoints::New();
#if defined(__APPLE__) || defined(_WIN32)
  pts->SetNumberOfPoints(2);
  positionLabel->SetPoints(pts);
  pts->Delete();
//#else
//        pts->SetNumberOfPoints(2);
//        rubberBand->SetPoints(pts);
//        pts->Delete();

//        vtkCellArray *lines  = vtkCellArray::New();
//        vtkIdType  ids[2] = { 0, 1 };
//        lines->InsertNextCell(2, ids);
//        rubberBand->SetLines(lines);
//        lines->Delete();
#endif

  positionLabelMapper = proxy.CreatePositionLabelMapper();
  positionLabelMapper->SetInputData(positionLabel);

  positionLabelActor  = vtkActor2D::New();
  positionLabelActor->SetMapper(positionLabelMapper);
  positionLabelActor->GetProperty()->SetColor(0., 0., 0.);
}

PositionLabelCurve::~PositionLabelCurve() {
  positionLabel->Delete();
  positionLabelMapper->Delete();
  positionLabelActor->Delete();
}

// ****************************************************************************
//  Method: PositionLabelCurve::OnTimer
//
//  Purpose:
//    Handles the timer event.  For Navigate2D, this means the user has
//    pressed a mouse key and that it is time to sample the mouse position
//    to see if the view should be panned or zoomed.
//
// ****************************************************************************

void
PositionLabelCurve::OnTimer(void)
{
    vtkRenderWindowInteractor *rwi = Interactor;

    int Pos[2];
    rwi->GetEventPosition(Pos);

    switch (State)
    {
      case VTKIS_PAN:
        PanCamera(Pos[0], Pos[1]);

        rwi->CreateTimer(VTKI_TIMER_UPDATE);
        break;

      case VTKIS_DOLLY:
        ZoomCamera(Pos[0], Pos[1]);

        rwi->CreateTimer(VTKI_TIMER_UPDATE);
        break;

      default:
        break;
    }
}


// ****************************************************************************
//  Method: PositionLabelCurve::StartLeftButtonAction
//
//  Purpose:
//    Handles the left button being pushed down.  For Navigate2D, this means
//     panning.
//
// ****************************************************************************

void
PositionLabelCurve::StartLeftButtonAction()
{
    StartPan();
}


// ****************************************************************************
//  Method: PositionLabelCurve::EndLeftButtonAction
//
//  Purpose:
//    Handles the left button being released.  For Navigate2D, this means
//    panning.
//
// ****************************************************************************

void
PositionLabelCurve::EndLeftButtonAction()
{
    EndPan();

    IssueViewCallback();
}


// ****************************************************************************
//  Method: PositionLabelCurve::StartMiddleButtonAction
//
//  Purpose:
//    Handles the middle button being pushed down.  For Navigate2D, this 
//    means zooming.
//
// ****************************************************************************

void
PositionLabelCurve::StartMiddleButtonAction()
{
    StartDolly();
}


// ****************************************************************************
//  Method: PositionLabelCurve::EndMiddleButtonAction
//
//  Purpose:
//    Handles the middle button being released.  For Navigate2D, this means
//    zooming.
//
// ****************************************************************************

void
PositionLabelCurve::EndMiddleButtonAction()
{
    EndDolly();

    IssueViewCallback();
}

// ****************************************************************************
//  Method: PositionLabelCurve::OnMouseWheelForward()
//
//  Purpose:
//    Handles the mouse wheel turned backward.
//
// ****************************************************************************

void
PositionLabelCurve::OnMouseWheelForward()
{
    StartZoom();
    ZoomCamera2D(MotionFactor * 0.2 * this->MouseWheelMotionFactor);
    EndZoom();
    IssueViewCallback(true);
}

// ****************************************************************************
//  Method: PositionLabelCurve::OnMouseWheelBackward()
//
//  Purpose:
//    Handles the mouse wheel turned forward.  
//
// ****************************************************************************

void
PositionLabelCurve::OnMouseWheelBackward()
{
    StartZoom();
    ZoomCamera2D(MotionFactor * -0.2 * this->MouseWheelMotionFactor);
    EndZoom();
    IssueViewCallback(true);
}

// ****************************************************************************
//  Method: PositionLabelCurve::OnMouseMove
//
//  Purpose:
//      Update the x,y label as the mouse is moved
//
//  Arguments:
//      ctrl    Non-zero if the ctrl button is being held down.
//      shift   Non-zero if the shift button is being held down.
//      x       The x coordinate of the mouse in display coordinates.
//      y       The y coordinate of the mouse in display coordinates.
//
// ****************************************************************************

void
PositionLabelCurve::OnMouseMove()
{
    int x,y;

    Interactor->GetEventPosition(x, y);
// There may be a way to do this update less frequently
    SetCanvasViewport();

    if (AreCoordsInViewport(x, y)) {
        double displayX = (double) x;
        double displayY = (double) y;
        double dummyZ = 0.;

        VisWindow *vw = proxy;
// Convert position to viewport coordinates.
        vtkRenderer *canvas = proxy.GetCanvas();

        canvas->DisplayToNormalizedDisplay(displayX, displayY);
        canvas->NormalizedDisplayToViewport(displayX, displayY);
        canvas->ViewportToNormalizedViewport(displayX, displayY);
// Translate viewport to 2D or domain/range
        switch (vw->GetWindowMode())
        {
          case WINMODE_2D:
            {
            const avtView2D view2D = vw->GetView2D();
            displayX = view2D.window[0] +
                       ((view2D.window[1] - view2D.window[0]) * displayX);
            displayY = view2D.window[2] +
                       ((view2D.window[3] - view2D.window[2]) * displayY);
            }
            break;
          case WINMODE_CURVE:
            {
            avtViewCurve newViewCurve = vw->GetViewCurve();
            displayX = newViewCurve.domain[0] +
                ((newViewCurve.domain[1] - newViewCurve.domain[0]) * displayX);
            displayY = newViewCurve.range[0] +
                ((newViewCurve.range[1] - newViewCurve.range[0]) * displayY);
            }
            break;
// Or translate to world coordinates
          default:
            {
            canvas->NormalizedViewportToView(displayX, displayY, dummyZ);
            canvas->ViewToWorld(displayX, displayY, dummyZ);
            }
            break;
        }

        vtkViewport *ren = proxy.GetBackground();
        ren->AddActor2D(positionLabelActor);
        vtkPoints *pts = positionLabel->GetPoints();
// Coordinates to draw at
        pts->SetPoint(0, (double) x, (double) y, 0.);
// Coordinates to display in text
        pts->SetPoint(1, displayX, displayY, 0.);
        positionLabelMapper->RenderOverlay(ren, positionLabelActor);
    } else {
        vtkViewport *ren = proxy.GetBackground();
        ren->RemoveActor2D(positionLabelActor);
    }

// Ensure the movement is handled as needed
    VisitInteractor::OnMouseMove();
}

// ****************************************************************************
//  Method: PositionLabelCurve::SetCanvasViewport
//
//  Purpose:
//      Sets where the canvas is in display coordinates so that x,y label can
//      be restricted to rendering inside the canvas.
//
// ****************************************************************************

void
PositionLabelCurve::SetCanvasViewport(void)
{
    vtkRenderer *ren = proxy.GetCanvas();

    canvasDeviceMinX = 0.;
    canvasDeviceMinY = 0.;
    ren->NormalizedViewportToViewport(canvasDeviceMinX, canvasDeviceMinY);
    ren->ViewportToNormalizedDisplay(canvasDeviceMinX, canvasDeviceMinY);
    ren->NormalizedDisplayToDisplay(canvasDeviceMinX, canvasDeviceMinY);

    canvasDeviceMaxX = 1.;
    canvasDeviceMaxY = 1.;
    ren->NormalizedViewportToViewport(canvasDeviceMaxX, canvasDeviceMaxY);
    ren->ViewportToNormalizedDisplay(canvasDeviceMaxX, canvasDeviceMaxY);
    ren->NormalizedDisplayToDisplay(canvasDeviceMaxX, canvasDeviceMaxY);
}

// ****************************************************************************
//  Method: PositionLabelCurve::AreCoordsInViewport
//
//  Purpose:
//      Takes coordinates and makes sure they are in the viewport.
//
//  Arguments:
//      x      X coordinate in display coordinates.
//      y      Y coordinate in display coordinates.
//
//  Note:    This routine assumes the canvasDevice[Min|Max][X|Y] has
//           already been set.
//
// ****************************************************************************

bool
PositionLabelCurve::AreCoordsInViewport(int &x, int &y)
{
    if (x < canvasDeviceMinX || x > canvasDeviceMaxX) return false;
    if (y < canvasDeviceMinY || y > canvasDeviceMaxY) return false;
    return true;
}


// ****************************************************************************
//  Method: PositionLabelCurve::PanCamera
//
//  Purpose:
//    Handle panning the camera.
//
// ****************************************************************************

void
PositionLabelCurve::PanCamera(const int x, const int y)
{
    vtkRenderWindowInteractor *rwi = Interactor;

    if ((OldX != x) || (OldY != y))
    {
        //
        // Determine the size of the window.
        //
        int       size[2];

        rwi->GetSize(size);

        //
        // Get the current view information.
        //
        VisWindow *vw = proxy;

        double    viewport[4];
        double    pan[2];

        avtViewCurve newViewCurve = vw->GetViewCurve();

        pan[0] = (double)(x - OldX) /
                 ((newViewCurve.viewport[1] - newViewCurve.viewport[0]) *
                  (double)(size[0])) *
                 (newViewCurve.domain[1] - newViewCurve.domain[0]);
        pan[1] = (double)(y - OldY) /
                 ((newViewCurve.viewport[3] - newViewCurve.viewport[2]) *
                  (double)(size[1])) *
                 (newViewCurve.range[1] - newViewCurve.range[0]);

        newViewCurve.domain[0] -= pan[0];
        newViewCurve.domain[1] -= pan[0];
        newViewCurve.range[0]  -= pan[1];
        newViewCurve.range[1]  -= pan[1];

        vw->SetViewCurve(newViewCurve);

        OldX = x;
        OldY = y;
        rwi->Render();
    }
}

// ****************************************************************************
//  Method: PositionLabelCurve::ZoomCamera
//
//  Purpose:
//    Handle zooming the camera.
//
// ****************************************************************************

void
PositionLabelCurve::ZoomCamera(const int x, const int y)
{
  if (OldY != y)
  {
      //
      // Calculate the zoom factor.
      //
      double dyf = MotionFactor * (double)(y - OldY) /
                       (double)(Center[1]);

      ZoomCamera(dyf);

      OldX = x;
      OldY = y;
  }
}

// ****************************************************************************
// Method: PositionLabelCurve::ZoomCamera
//
// Purpose:
//   Zoom the camera based on a zoom factor.
//
// Arguments:
//   f : The zoom factor.
//
// ****************************************************************************

void
PositionLabelCurve::ZoomCamera(double f)
{
    double zoomFactor = pow((double)1.1, f);

    //
    // Calculate the new parallel scale.
    //
    VisWindow *vw = proxy;

    avtViewCurve newViewCurve = vw->GetViewCurve();
    double dX = ((1. / zoomFactor) - 1.) *
                ((newViewCurve.domain[1] - newViewCurve.domain[0]) / 2.);
    double dY = ((1. / zoomFactor) - 1.) *
                ((newViewCurve.range[1] - newViewCurve.range[0]) / 2.);

    newViewCurve.domain[0] -= dX;
    newViewCurve.domain[1] += dX;
    newViewCurve.range[0]  -= dY;
    newViewCurve.range[1]  += dY;

    vw->SetViewCurve(newViewCurve);
}

