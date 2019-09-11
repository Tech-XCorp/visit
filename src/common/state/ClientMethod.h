// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef CLIENTMETHOD_H
#define CLIENTMETHOD_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: ClientMethod
//
// Purpose:
//    This class contains the attributes needed to make one client execute a method on another client.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API ClientMethod : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    ClientMethod();
    ClientMethod(const ClientMethod &obj);
protected:
    // These constructors are for objects derived from this class
    ClientMethod(private_tmfs_t tmfs);
    ClientMethod(const ClientMethod &obj, private_tmfs_t tmfs);
public:
    virtual ~ClientMethod();

    virtual ClientMethod& operator = (const ClientMethod &obj);
    virtual bool operator == (const ClientMethod &obj) const;
    virtual bool operator != (const ClientMethod &obj) const;
private:
    void Init();
    void Copy(const ClientMethod &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectMethodName();
    void SelectIntArgs();
    void SelectDoubleArgs();
    void SelectStringArgs();

    // Property setting methods
    void SetMethodName(const std::string &methodName_);
    void SetIntArgs(const intVector &intArgs_);
    void SetDoubleArgs(const doubleVector &doubleArgs_);
    void SetStringArgs(const stringVector &stringArgs_);

    // Property getting methods
    const std::string  &GetMethodName() const;
          std::string  &GetMethodName();
    const intVector    &GetIntArgs() const;
          intVector    &GetIntArgs();
    const doubleVector &GetDoubleArgs() const;
          doubleVector &GetDoubleArgs();
    const stringVector &GetStringArgs() const;
          stringVector &GetStringArgs();


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void ClearArgs();
    void AddArgument(int);
    void AddArgument(double);
    void AddArgument(const std::string &);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_methodName = 0,
        ID_intArgs,
        ID_doubleArgs,
        ID_stringArgs,
        ID__LAST
    };

private:
    std::string  methodName;
    intVector    intArgs;
    doubleVector doubleArgs;
    stringVector stringArgs;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define CLIENTMETHOD_TMFS "si*d*s*"

#endif
