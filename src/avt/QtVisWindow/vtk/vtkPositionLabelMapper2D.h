// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef __vtkPositionLabelMapper2D_h
#define __vtkPositionLabelMapper2D_h
#include <qtviswindow_exports.h>

#include "vtkPolyDataMapper2D.h"

class QWidget;
struct vtkPositionLabelMapper2DPrivate;

// ***************************************************************************
//  Modifications:
//    Alister Maguire, Thu Jun 24 10:57:30 PDT 2021
//    Changed the name of class variable "d" to "privateInstance".
//
// ***************************************************************************
class QTVISWINDOW_API vtkPositionLabelMapper2D : public vtkPolyDataMapper2D
{
public:
  vtkTypeMacro(vtkPositionLabelMapper2D,vtkPolyDataMapper2D);
  static vtkPositionLabelMapper2D *New();

  // Description:
  // Set the widget over which the drawing will happen.
  void SetWidget(QWidget *widget);

  // Description:
  // Actually draw the poly data.
  void RenderOverlay(vtkViewport* viewport, vtkActor2D* actor) override;

  // Description:
  // Release graphics resources.
  void ReleaseGraphicsResources(vtkWindow *) override;

protected:
  vtkPositionLabelMapper2D();
  ~vtkPositionLabelMapper2D();

//  void RenderOverlay_X11(vtkViewport* viewport, vtkActor2D* actor);
  void RenderOverlay_Qt(vtkViewport* viewport, vtkActor2D* actor);

  vtkPositionLabelMapper2DPrivate *privateInstance;

private:
  vtkPositionLabelMapper2D(const vtkPositionLabelMapper2D&);
  void operator=(const vtkPositionLabelMapper2D&);

};


#endif

