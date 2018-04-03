}

// ICAP client is done sending adapted response
void ICAPClientReqmodPrecache::noteSourceFinish(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceFinish() called\n");
    //tell ClientHttpRequest that we expect no more response data
    leakTouch(p, MsgPipeLeaker);
    http->doneAdapting();
    stop(notifyNone);
}

// ICAP client is aborting
void ICAPClientReqmodPrecache::noteSourceAbort(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceAbort() called\n");
    leakTouch(p, MsgPipeLeaker);
    stop(notifyOwner);
}

// internal cleanup
void ICAPClientReqmodPrecache::stop(Notify notify)
{
    if (virgin != NULL) {
        leakTouch(virgin.getRaw(), MsgPipeLeaker);
