}

// ICAP client aborting
void ICAPClientReqmodPrecache::noteSinkAbort(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSinkAbort() called\n");
    stop(notifyOwner);
}

// ICAP client starts sending adapted response
// ICAP client has received new HTTP headers (if any) at this point
void ICAPClientReqmodPrecache::noteSourceStart(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceStart() called\n");
    leakTouch(adapted.getRaw(), MsgPipeLeaker);
    http->takeAdaptedHeaders(adapted->data->header);
    noteSourceProgress(p);
}

// ICAP client sends more data
void ICAPClientReqmodPrecache::noteSourceProgress(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceProgress() called\n");
    //tell ClientHttpRequest to store a fresh portion of the adapted response

    leakTouch(p, MsgPipeLeaker);
