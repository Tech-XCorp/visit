#ifndef MATERIALATTRIBUTES_H
#define MATERIALATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: MaterialAttributes
//
// Purpose:
//    Attributes to control material interface reconstruction
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Thu Aug 18 17:37:44 PST 2005
//
// Modifications:
//   
// ****************************************************************************

class STATE_API MaterialAttributes : public AttributeSubject
{
public:
    enum Algorithm
    {
        Tetrahedral,
        ZooClipping,
        Isovolume
    };

    MaterialAttributes();
    MaterialAttributes(const MaterialAttributes &obj);
    virtual ~MaterialAttributes();

    virtual MaterialAttributes& operator = (const MaterialAttributes &obj);
    virtual bool operator == (const MaterialAttributes &obj) const;
    virtual bool operator != (const MaterialAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetSmoothing(bool smoothing_);
    void SetForceMIR(bool forceMIR_);
    void SetCleanZonesOnly(bool cleanZonesOnly_);
    void SetNeedValidConnectivity(bool needValidConnectivity_);
    void SetAlgorithm(Algorithm algorithm_);
    void SetSimplifyHeavilyMixedZones(bool simplifyHeavilyMixedZones_);
    void SetMaxMaterialsPerZone(int maxMaterialsPerZone_);
    void SetIsoVolumeFraction(float isoVolumeFraction_);

    // Property getting methods
    bool  GetSmoothing() const;
    bool  GetForceMIR() const;
    bool  GetCleanZonesOnly() const;
    bool  GetNeedValidConnectivity() const;
    Algorithm GetAlgorithm() const;
    bool  GetSimplifyHeavilyMixedZones() const;
    int   GetMaxMaterialsPerZone() const;
    float GetIsoVolumeFraction() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string Algorithm_ToString(Algorithm);
    static bool Algorithm_FromString(const std::string &, Algorithm &);
protected:
    static std::string Algorithm_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    bool  smoothing;
    bool  forceMIR;
    bool  cleanZonesOnly;
    bool  needValidConnectivity;
    int   algorithm;
    bool  simplifyHeavilyMixedZones;
    int   maxMaterialsPerZone;
    float isoVolumeFraction;
};

#endif
