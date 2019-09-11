// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef MODELFITATTS_H
#define MODELFITATTS_H
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: ModelFitAtts
//
// Purpose:
//    This file contains attributes for the ModelFit operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class ModelFitAtts : public AttributeSubject
{
public:
    enum Spaces
    {
        VARIABLE,
        NORMAL,
        LOG,
        PROBABILITY
    };
    enum Stats
    {
        AVERAGE,
        MIN,
        MAX,
        NONE
    };
    enum Distances
    {
        EUCLIDEAN,
        MANHATTAN,
        MAXIMUM
    };

    // These constructors are for objects of this class
    ModelFitAtts();
    ModelFitAtts(const ModelFitAtts &obj);
protected:
    // These constructors are for objects derived from this class
    ModelFitAtts(private_tmfs_t tmfs);
    ModelFitAtts(const ModelFitAtts &obj, private_tmfs_t tmfs);
public:
    virtual ~ModelFitAtts();

    virtual ModelFitAtts& operator = (const ModelFitAtts &obj);
    virtual bool operator == (const ModelFitAtts &obj) const;
    virtual bool operator != (const ModelFitAtts &obj) const;
private:
    void Init();
    void Copy(const ModelFitAtts &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectVars();
    void SelectNumVars();
    void SelectTuples();
    void SelectStatTuples();
    void SelectNumTups();
    void SelectThold();
    void SelectSelectionType();
    void SelectDistanceType();
    void SelectInputSpace();
    void SelectModelNames();
    void SelectModelNums();

    // Property setting methods
    void SetVars(const stringVector &Vars_);
    void SetNumVars(const intVector &numVars_);
    void SetTuples(const doubleVector &Tuples_);
    void SetStatTuples(const unsignedCharVector &StatTuples_);
    void SetNumTups(const intVector &numTups_);
    void SetThold(const doubleVector &thold_);
    void SetSelectionType(const intVector &selectionType_);
    void SetDistanceType(const intVector &distanceType_);
    void SetInputSpace(const intVector &inputSpace_);
    void SetModelNames(const stringVector &modelNames_);
    void SetModelNums(const intVector &modelNums_);

    // Property getting methods
    const stringVector       &GetVars() const;
          stringVector       &GetVars();
    const intVector          &GetNumVars() const;
          intVector          &GetNumVars();
    const doubleVector       &GetTuples() const;
          doubleVector       &GetTuples();
    const unsignedCharVector &GetStatTuples() const;
          unsignedCharVector &GetStatTuples();
    const intVector          &GetNumTups() const;
          intVector          &GetNumTups();
    const doubleVector       &GetThold() const;
          doubleVector       &GetThold();
    const intVector          &GetSelectionType() const;
          intVector          &GetSelectionType();
    const intVector          &GetDistanceType() const;
          intVector          &GetDistanceType();
    const intVector          &GetInputSpace() const;
          intVector          &GetInputSpace();
    const stringVector       &GetModelNames() const;
          stringVector       &GetModelNames();
    const intVector          &GetModelNums() const;
          intVector          &GetModelNums();

    // Enum conversion functions
    static std::string Spaces_ToString(Spaces);
    static bool Spaces_FromString(const std::string &, Spaces &);
protected:
    static std::string Spaces_ToString(int);
public:
    static std::string Stats_ToString(Stats);
    static bool Stats_FromString(const std::string &, Stats &);
protected:
    static std::string Stats_ToString(int);
public:
    static std::string Distances_ToString(Distances);
    static bool Distances_FromString(const std::string &, Distances &);
protected:
    static std::string Distances_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_Vars = 0,
        ID_numVars,
        ID_Tuples,
        ID_StatTuples,
        ID_numTups,
        ID_thold,
        ID_selectionType,
        ID_distanceType,
        ID_inputSpace,
        ID_modelNames,
        ID_modelNums,
        ID__LAST
    };

private:
    stringVector       Vars;
    intVector          numVars;
    doubleVector       Tuples;
    unsignedCharVector StatTuples;
    intVector          numTups;
    doubleVector       thold;
    intVector          selectionType;
    intVector          distanceType;
    intVector          inputSpace;
    stringVector       modelNames;
    intVector          modelNums;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define MODELFITATTS_TMFS "s*i*d*u*i*d*i*i*i*s*i*"

#endif
