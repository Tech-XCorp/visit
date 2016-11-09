/*****************************************************************************
*
* Copyright (c) 2000 - 2016, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef SEEDMEATTRIBUTES_H
#define SEEDMEATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: SeedMeAttributes
//
// Purpose:
//    This class contains the attributes needed to interact with SeedMe.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API SeedMeAttributes : public AttributeSubject
{
public:
    enum CollectionMode
    {
        COLLECTION_NEW,
        COLLECTION_UPDATE
    };
    enum Sharing
    {
        SHARING_PRIVATE,
        SHARING_GROUP,
        SHARING_PUBLIC
    };
    enum QueryAction
    {
        LIST_COL,
        FIND_COL,
        QUERY_COL
    };
    enum QueryCollectionValues
    {
        QUERY_ALL,
        QUERY_KEY_VALUE,
        QUERY_TICKER,
        QUERY_URL
    };
    enum Download
    {
        DOWNLOAD_ALL,
        DOWNLOAD_VIDEO,
        DOWNLOAD_NAME
    };
    enum DownloadQuality
    {
        DOWNLOAD_Q_ALL,
        DOWNLOAD_Q_BEST,
        DOWNLOAD_Q_HIGHEST,
        DOWNLOAD_Q_HIGH,
        DOWNLOAD_Q_MEDIUM,
        DOWNLOAD_Q_LOW,
        DOWNLOAD_Q_LOWEST
    };

    // These constructors are for objects of this class
    SeedMeAttributes();
    SeedMeAttributes(const SeedMeAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    SeedMeAttributes(private_tmfs_t tmfs);
    SeedMeAttributes(const SeedMeAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~SeedMeAttributes();

    virtual SeedMeAttributes& operator = (const SeedMeAttributes &obj);
    virtual bool operator == (const SeedMeAttributes &obj) const;
    virtual bool operator != (const SeedMeAttributes &obj) const;
private:
    void Init();
    void Copy(const SeedMeAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectCollectionTitle();
    void SelectCollectionDescription();
    void SelectKeyValue();
    void SelectCollectionEmails();
    void SelectCurrentTitle();
    void SelectCurrentDescription();
    void SelectSequenceTitle();
    void SelectSequenceDescription();
    void SelectOperationResult();
    void SelectQueryColID();
    void SelectQueryKeyValue();
    void SelectDownloadName();
    void SelectQuickCollectionTitle();
    void SelectQuickCollectionEmails();

    // Property setting methods
    void SetCollectionMode(CollectionMode collectionMode_);
    void SetCollectionID(int collectionID_);
    void SetSharing(Sharing sharing_);
    void SetCollectionTitle(const std::string &collectionTitle_);
    void SetCollectionDescription(const std::string &collectionDescription_);
    void SetOverwriteFiles(bool overwriteFiles_);
    void SetKeyValue(const std::string &keyValue_);
    void SetCollectionEmails(const std::string &collectionEmails_);
    void SetUploadCurrentFile(bool uploadCurrentFile_);
    void SetCurrentTitle(const std::string &currentTitle_);
    void SetCurrentDescription(const std::string &currentDescription_);
    void SetUploadSequenceFile(bool uploadSequenceFile_);
    void SetSequenceTitle(const std::string &sequenceTitle_);
    void SetSequenceDescription(const std::string &sequenceDescription_);
    void SetCreateVideo(bool createVideo_);
    void SetFrameRate(int frameRate_);
    void SetOperationResult(const std::string &operationResult_);
    void SetQueryAction(QueryAction queryAction_);
    void SetQueryColID(const std::string &queryColID_);
    void SetQueryKeyValue(const std::string &queryKeyValue_);
    void SetQueryCollectionValues(QueryCollectionValues queryCollectionValues_);
    void SetDownloadCollectionID(int downloadCollectionID_);
    void SetDownloadType(Download downloadType_);
    void SetDownloadName(const std::string &downloadName_);
    void SetQuickSharing(Sharing quickSharing_);
    void SetQuickCollectionTitle(const std::string &quickCollectionTitle_);
    void SetQuickCollectionEmails(const std::string &quickCollectionEmails_);
    void SetQuickFrameRate(int quickFrameRate_);
    void SetQuickDownloadType(DownloadQuality quickDownloadType_);

    // Property getting methods
    CollectionMode    GetCollectionMode() const;
    int               GetCollectionID() const;
    Sharing           GetSharing() const;
    const std::string &GetCollectionTitle() const;
          std::string &GetCollectionTitle();
    const std::string &GetCollectionDescription() const;
          std::string &GetCollectionDescription();
    bool              GetOverwriteFiles() const;
    const std::string &GetKeyValue() const;
          std::string &GetKeyValue();
    const std::string &GetCollectionEmails() const;
          std::string &GetCollectionEmails();
    bool              GetUploadCurrentFile() const;
    const std::string &GetCurrentTitle() const;
          std::string &GetCurrentTitle();
    const std::string &GetCurrentDescription() const;
          std::string &GetCurrentDescription();
    bool              GetUploadSequenceFile() const;
    const std::string &GetSequenceTitle() const;
          std::string &GetSequenceTitle();
    const std::string &GetSequenceDescription() const;
          std::string &GetSequenceDescription();
    bool              GetCreateVideo() const;
    int               GetFrameRate() const;
    const std::string &GetOperationResult() const;
          std::string &GetOperationResult();
    QueryAction       GetQueryAction() const;
    const std::string &GetQueryColID() const;
          std::string &GetQueryColID();
    const std::string &GetQueryKeyValue() const;
          std::string &GetQueryKeyValue();
    QueryCollectionValues GetQueryCollectionValues() const;
    int               GetDownloadCollectionID() const;
    Download          GetDownloadType() const;
    const std::string &GetDownloadName() const;
          std::string &GetDownloadName();
    Sharing           GetQuickSharing() const;
    const std::string &GetQuickCollectionTitle() const;
          std::string &GetQuickCollectionTitle();
    const std::string &GetQuickCollectionEmails() const;
          std::string &GetQuickCollectionEmails();
    int               GetQuickFrameRate() const;
    DownloadQuality   GetQuickDownloadType() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string CollectionMode_ToString(CollectionMode);
    static bool CollectionMode_FromString(const std::string &, CollectionMode &);
protected:
    static std::string CollectionMode_ToString(int);
public:
    static std::string Sharing_ToString(Sharing);
    static bool Sharing_FromString(const std::string &, Sharing &);
protected:
    static std::string Sharing_ToString(int);
public:
    static std::string QueryAction_ToString(QueryAction);
    static bool QueryAction_FromString(const std::string &, QueryAction &);
protected:
    static std::string QueryAction_ToString(int);
public:
    static std::string QueryCollectionValues_ToString(QueryCollectionValues);
    static bool QueryCollectionValues_FromString(const std::string &, QueryCollectionValues &);
protected:
    static std::string QueryCollectionValues_ToString(int);
public:
    static std::string Download_ToString(Download);
    static bool Download_FromString(const std::string &, Download &);
protected:
    static std::string Download_ToString(int);
public:
    static std::string DownloadQuality_ToString(DownloadQuality);
    static bool DownloadQuality_FromString(const std::string &, DownloadQuality &);
protected:
    static std::string DownloadQuality_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_collectionMode = 0,
        ID_collectionID,
        ID_sharing,
        ID_collectionTitle,
        ID_collectionDescription,
        ID_overwriteFiles,
        ID_keyValue,
        ID_collectionEmails,
        ID_uploadCurrentFile,
        ID_currentTitle,
        ID_currentDescription,
        ID_uploadSequenceFile,
        ID_sequenceTitle,
        ID_sequenceDescription,
        ID_createVideo,
        ID_frameRate,
        ID_operationResult,
        ID_queryAction,
        ID_queryColID,
        ID_queryKeyValue,
        ID_queryCollectionValues,
        ID_downloadCollectionID,
        ID_downloadType,
        ID_downloadName,
        ID_quickSharing,
        ID_quickCollectionTitle,
        ID_quickCollectionEmails,
        ID_quickFrameRate,
        ID_quickDownloadType,
        ID__LAST
    };

private:
    int         collectionMode;
    int         collectionID;
    int         sharing;
    std::string collectionTitle;
    std::string collectionDescription;
    bool        overwriteFiles;
    std::string keyValue;
    std::string collectionEmails;
    bool        uploadCurrentFile;
    std::string currentTitle;
    std::string currentDescription;
    bool        uploadSequenceFile;
    std::string sequenceTitle;
    std::string sequenceDescription;
    bool        createVideo;
    int         frameRate;
    std::string operationResult;
    int         queryAction;
    std::string queryColID;
    std::string queryKeyValue;
    int         queryCollectionValues;
    int         downloadCollectionID;
    int         downloadType;
    std::string downloadName;
    int         quickSharing;
    std::string quickCollectionTitle;
    std::string quickCollectionEmails;
    int         quickFrameRate;
    int         quickDownloadType;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define SEEDMEATTRIBUTES_TMFS "iiissbssbssbssbisissiiisissii"

#endif