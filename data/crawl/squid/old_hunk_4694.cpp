 */

/*
 * ServerStateData is a class for common elements of Server-side modules
 * such as http.cc and ftp.cc.  It was invented to make ICAP code simpler.
 */

#ifndef SQUID_SERVER_H
#define SQUID_SERVER_H

#include "StoreIOBuffer.h"
#include "forward.h"

#if ICAP_CLIENT
#include "ICAP/ICAPServiceRep.h"

class ICAPClientRespmodPrecache;

class ICAPAccessCheck;
#endif

class ServerStateData
{

public:
    ServerStateData(FwdState *);
    virtual ~ServerStateData();

#if ICAP_CLIENT
    virtual bool takeAdaptedHeaders(HttpReply *) = 0;
    virtual bool takeAdaptedBody(MemBuf *) = 0;
    virtual void finishAdapting() = 0;
    virtual void abortAdapting() = 0;
    virtual void icapSpaceAvailable() = 0;
    virtual void icapAclCheckDone(ICAPServiceRep::Pointer) = 0;
#endif

public:
    // should be protected
    StoreEntry *entry;
    FwdState::Pointer fwd;
    HttpRequest *request;
    HttpReply *reply;

protected:
#if ICAP_CLIENT

    ICAPClientRespmodPrecache *icap;
    bool icapAccessCheckPending;
    bool startIcap(ICAPServiceRep::Pointer);
#endif

};

#endif /* SQUID_SERVER_H */
