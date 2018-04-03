
CBDATA_CLASS_INIT(ICAPClientRespmodPrecache);

ICAPClientRespmodPrecache::ICAPClientRespmodPrecache(ICAPServiceRep::Pointer aService): service(aService), serverState(NULL), virgin(NULL), adapted(NULL)
{
    debug(93,5)("ICAPClientRespmodPrecache constructed, this=%p\n", this);
}

ICAPClientRespmodPrecache::~ICAPClientRespmodPrecache()
{
    stop(notifyNone);
    cbdataReferenceDone(serverState);
    debug(93,5)("ICAPClientRespmodPrecache destructed, this=%p\n", this);

    if (virgin != NULL)
        freeVirgin();

    if (adapted != NULL)
        freeAdapted();

    service = NULL;
}

void ICAPClientRespmodPrecache::startRespMod(ServerStateData *anServerState, HttpRequest *request, HttpReply *reply)
{
    serverState = cbdataReference(anServerState);

    virgin = new MsgPipe("virgin"); // this is the place to create a refcount ptr
    virgin->source = this;
    virgin->data = new MsgPipeData;
    virgin->data->setCause(request);
    virgin->data->setHeader(reply);
    virgin->data->body = new MemBuf;
    virgin->data->body->init(ICAP::MsgPipeBufSizeMin, ICAP::MsgPipeBufSizeMax);

    adapted = new MsgPipe("adapted");
    adapted->sink = this;
#if ICAP_ANCHOR_LOOPBACK

    adapted->data = new MsgPipeData;
    adapted->data->setCause(request); // should not hurt
#else

    ICAPInitXaction(service, virgin, adapted);
#endif

    virgin->sendSourceStart(); // we may have virgin data to provide
    adapted->sendSinkNeed();   // we want adapted response, eventially
}

void ICAPClientRespmodPrecache::sendMoreData(StoreIOBuffer buf)
{
    debug(93,5)("ICAPClientRespmodPrecache::sendMoreData() called\n");
    //debugs(93,0,HERE << "appending " << buf.length << " bytes");
    //debugs(93,0,HERE << "body.contentSize = " << virgin->data->body->contentSize());
    //buf.dump();
    /*
     * The caller is responsible for not giving us more data
     * than will fit in body MemBuf.  Caller should use
     * potentialSpaceSize() to find out how much we can hold.
     */
    virgin->data->body->append(buf.data, buf.length);
    virgin->sendSourceProgress();
}

int
ICAPClientRespmodPrecache::potentialSpaceSize()
{
    if (virgin == NULL)
        return 0;

    return (int) virgin->data->body->potentialSpaceSize();
}

// ServerStateData says we have the entire HTTP message
void ICAPClientRespmodPrecache::doneSending()
{
    debug(93,5)("ICAPClientRespmodPrecache::doneSending() called\n");

#if ICAP_ANCHOR_LOOPBACK
    /* simple assignments are not the right way to do this */
    adapted->data->setHeader(virgin->data->header);
    adapted->data->body = virgin->data->body;
    noteSourceFinish(adapted);
    return;
#else

    virgin->sendSourceFinish();
#endif
}

// ServerStateData tells us to abort
void ICAPClientRespmodPrecache::ownerAbort()
{
    debug(93,5)("ICAPClientRespmodPrecache::ownerAbort() called\n");
    stop(notifyIcap);
}

// ICAP client needs more virgin response data
void ICAPClientRespmodPrecache::noteSinkNeed(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSinkNeed() called\n");

    if (virgin->data->body->potentialSpaceSize())
        serverState->icapSpaceAvailable();
}

// ICAP client aborting
void ICAPClientRespmodPrecache::noteSinkAbort(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSinkAbort() called\n");
    stop(notifyOwner);
}

// ICAP client starts sending adapted response
// ICAP client has received new HTTP headers (if any) at this point
void ICAPClientRespmodPrecache::noteSourceStart(MsgPipe *p)
{
    debugs(93,5, HERE << "ICAPClientRespmodPrecache::noteSourceStart() called");

    HttpReply *reply = dynamic_cast<HttpReply*>(adapted->data->header);
    /*
     *	The ICAP reply MUST have a new HTTP reply header, or else
     *	it is an invalid ICAP message.  Invalid ICAP messages should
     *	be handled prior to this point.
     */
    assert(reply); // check that ICAP xaction created the right object
    assert(reply == adapted->data->header);
