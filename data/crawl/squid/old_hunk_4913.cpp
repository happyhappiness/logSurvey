}

// ICAP client aborting
void ICAPClientSideHook::noteSinkAbort(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSinkAbort() called\n");
    stop(notifyOwner);
}

// ICAP client starts sending adapted response
// ICAP client has received new HTTP headers (if any) at this point
void ICAPClientSideHook::noteSourceStart(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSourceStart() called\n");
    leakTouch(adapted.getRaw(), MsgPipeLeaker);
    http->takeAdaptedHeaders(adapted->data->header);
    noteSourceProgress(p);
}

// ICAP client sends more data
void ICAPClientSideHook::noteSourceProgress(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSourceProgress() called\n");
    //tell ClientHttpRequest to store a fresh portion of the adapted response

    leakTouch(p, MsgPipeLeaker);
