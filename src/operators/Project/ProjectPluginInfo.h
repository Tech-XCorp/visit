// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: ProjectPluginInfo.h
// ************************************************************************* //

#ifndef PROJECT_PLUGIN_INFO_H
#define PROJECT_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class ProjectAttributes;

// ****************************************************************************
//  Class: ProjectPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Project operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class ProjectGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class ProjectCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual ProjectGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class ProjectGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual ProjectCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class ProjectViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual ProjectCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const avtPlotMetaData &plot,
                                        const bool fromDefault);
    virtual void UpdateOperatorAtts(AttributeSubject *atts,
                                    const avtPlotMetaData &plot);
    virtual const char *GetMenuName() const;

    static void InitializeGlobalObjects();
  private:
    static ProjectAttributes *defaultAtts;
    static ProjectAttributes *clientAtts;
};

class ProjectViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual ProjectViewerEnginePluginInfo
{
  public:
    virtual const char **XPMIconData() const;
};

class ProjectEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual ProjectViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class ProjectScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual ProjectCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
