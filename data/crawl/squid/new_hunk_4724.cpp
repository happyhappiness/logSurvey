 *
 */

#ifndef SQUID_ICAPCLIENTRESPMODPRECACHE_H
#define SQUID_ICAPCLIENTRESPMODPRECACHE_H

#include "ICAPClientVector.h"

/*
 * ICAPClientRespmodPrecache implements the server-side pre-cache ICAP
 * vectoring point using ICAPClientVector as a parent.
 * ServerStateData is the Owner of this vectoring point.
 */

class ServerStateData;

class ICAPClientRespmodPrecache: public ICAPClientVector
{

public:
    ICAPClientRespmodPrecache(ICAPServiceRep::Pointer);

    // synchronous calls called by ServerStateData
    void startRespMod(ServerStateData *anServerState, HttpRequest *request, HttpReply *reply);

    // pipe source methods; called by ICAP while receiving the virgin message

    // pipe sink methods; called by ICAP while sending the adapted message
    virtual void noteSourceStart(MsgPipe *p);
    virtual void noteSourceProgress(MsgPipe *p);

protected:
    virtual void tellSpaceAvailable();
    virtual void tellDoneAdapting(); // deletes us
    virtual void tellAbortAdapting(); // deletes us

public:
    ServerStateData *serverState;

private:
    CBDATA_CLASS2(ICAPClientRespmodPrecache);
};

#endif /* SQUID_ICAPCLIENTRESPMODPRECACHE_H */
