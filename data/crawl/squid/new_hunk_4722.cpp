
CBDATA_CLASS_INIT(ICAPClientRespmodPrecache);

ICAPClientRespmodPrecache::ICAPClientRespmodPrecache(ICAPServiceRep::Pointer aService):
    ICAPClientVector(aService, "ICAPClientRespmodPrecache"), serverState(NULL)
{
}

void ICAPClientRespmodPrecache::startRespMod(ServerStateData *aServerState, HttpRequest *request, HttpReply *reply)
{
    serverState = cbdataReference(aServerState);
    startMod(serverState, request, reply);
}

// ICAP client starts sending adapted response
// ICAP client has received new HTTP headers (if any) at this point
void ICAPClientRespmodPrecache::noteSourceStart(MsgPipe *p)
{
    debugs(93,3, HERE << "ICAPClientRespmodPrecache::noteSourceStart() called");

    HttpReply *reply = dynamic_cast<HttpReply*>(adapted->data->header);
    /*
     * The ICAP reply MUST have a new HTTP reply header, or else
     * it is an invalid ICAP message.  Invalid ICAP messages should
     * be handled prior to this point.
     */
    assert(reply); // check that ICAP xaction created the right object
    assert(reply == adapted->data->header);
