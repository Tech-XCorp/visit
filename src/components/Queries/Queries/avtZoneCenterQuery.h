// ************************************************************************* //
//                          avtZoneCenterQuery.h                             //
// ************************************************************************* //

#ifndef AVT_ZONECZENTER_QUERY_H
#define AVT_ZONECZENTER_QUERY_H
#include <query_exports.h>

#include <avtDatasetQuery.h>


// ****************************************************************************
//  Class: avtZoneCenterQuery
//
//  Purpose:
//      This is a dataset query that returns the coordintes of a zone's center. 
//
//  Programmer: Kathleen Bonnell 
//  Creation:   May 25, 2004 
//
//  Modifications:
//    Kathleen Bonnell, Thu Dec 16 17:16:33 PST 2004
//    Add FindLocalCenter, FindGlobalCenter.
//
// ****************************************************************************

class QUERY_API avtZoneCenterQuery : public avtDatasetQuery
{
  public:
                             avtZoneCenterQuery();
    virtual                 ~avtZoneCenterQuery(); 

    virtual const char      *GetType(void) { return "avtZoneCenterQuery"; };
    virtual const char      *GetDescription(void) 
                                  { return "Getting zone center."; };

    virtual void             PerformQuery(QueryAttributes *);
    virtual bool             OriginalData(void) { return true; };

  protected:

    virtual void             Execute(vtkDataSet*, const int){;};

    bool                     FindGlobalCenter(float coord[3]);
    bool                     FindLocalCenter(float coord[3]);
};

#endif

