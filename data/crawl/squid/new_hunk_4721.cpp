 *
 */

#ifndef SQUID_ICAPCLIENTREQMODPRECACHE_H
#define SQUID_ICAPCLIENTREQMODPRECACHE_H

#include "ICAPClientVector.h"

/*
 * ICAPClientReqmodPrecache implements the ICAP client-side pre-cache
 * vectoring point using ICAPClientVector as a parent.
 * ClientHttpRequest is the Owner of this vectoring point.
 */

class ClientRequestContext;

class ICAPClientReqmodPrecache: public ICAPClientVector
{

public:
    ICAPClientReqmodPrecache(ICAPServiceRep::Pointer);

    // synchronous calls called by ClientHttpRequest
    void startReqMod(ClientHttpRequest *, HttpRequest *);

    // pipe source methods; called by ICAP while receiving the virgin message


    // pipe sink methods; called by ICAP while sending the adapted message
    virtual void noteSourceStart(MsgPipe *p);
    virtual void noteSourceProgress(MsgPipe *p);

protected:
    // used by ICAPClientVector because it does not know Owner type
    virtual void tellSpaceAvailable();
    virtual void tellDoneAdapting();
    virtual void tellAbortAdapting();
    virtual void stop(Notify notify);

public:
    ClientHttpRequest *http;
    BodyReader::Pointer body_reader;

private:
    // Hooks to BodyReader so HttpStateData can get the
    // adapted request body
    static BodyReadFunc readBody;
    static BodyAbortFunc abortBody;
    static BodyKickFunc kickBody;

    CBDATA_CLASS2(ICAPClientReqmodPrecache);
};

#endif /* SQUID_ICAPCLIENTSIDEHOOK_H */
