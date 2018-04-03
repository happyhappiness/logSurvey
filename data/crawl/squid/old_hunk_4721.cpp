 *
 */

#ifndef SQUID_ICAPCLIENTSIDEHOOK_H
#define SQUID_ICAPCLIENTSIDEHOOK_H

#include "MsgPipe.h"
#include "MsgPipeSource.h"
#include "MsgPipeSink.h"

/* The ICAP ClientReqmodPrecache implements message pipe sink and source interfaces.  It
 * helps client-side to marshall the incoming/virgin HTTP message (being
 * recieved from the HTTP client) to Squid's ICAP client module, using the
 * MsgPipe interface. The same interface is used to get the adapted HTTP
 * message back from the ICAP client. client-side is the "owner" of the
 * ICAPClientReqmodPrecache.
 */

class HttpRequest;

class ClientRequestContext;

class ICAPClientReqmodPrecache: public MsgPipeSource, public MsgPipeSink
{

public:
    ICAPClientReqmodPrecache(ICAPServiceRep::Pointer);
    virtual ~ICAPClientReqmodPrecache();

    // synchronous calls called by ClientHttpRequest
    void startReqMod(ClientHttpRequest *, HttpRequest *);
    void sendMoreData(StoreIOBuffer buf);
    void doneSending();
    void ownerAbort();
    int potentialSpaceSize();	/* how much data can we accept? */

    // pipe source methods; called by ICAP while receiving the virgin message
    virtual void noteSinkNeed(MsgPipe *p);
    virtual void noteSinkAbort(MsgPipe *p);

    // pipe sink methods; called by ICAP while sending the adapted message
    virtual void noteSourceStart(MsgPipe *p);
    virtual void noteSourceProgress(MsgPipe *p);
    virtual void noteSourceFinish(MsgPipe *p);
    virtual void noteSourceAbort(MsgPipe *p);

public:
    ICAPServiceRep::Pointer service;
    ClientHttpRequest *http;
    MsgPipe::Pointer virgin;
    MsgPipe::Pointer adapted;
    BodyReader::Pointer body_reader;

private:
    typedef enum { notifyNone, notifyOwner, notifyIcap } Notify;
    void stop(Notify notify);
    void freeVirgin();
    void freeAdapted();
    CBDATA_CLASS2(ICAPClientReqmodPrecache);

    // Hooks to BodyReader so HttpStateData can get the
    // adapted request body
    static BodyReadFunc readBody;
    static BodyAbortFunc abortBody;
    static BodyKickFunc kickBody;
};

#endif /* SQUID_ICAPCLIENTSIDEHOOK_H */
