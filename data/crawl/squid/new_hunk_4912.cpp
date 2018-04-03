}

// ClientHttpRequest says we have the entire HTTP message
void ICAPClientReqmodPrecache::doneSending()
{
    debug(93,3)("ICAPClientReqmodPrecache::doneSending() called\n");
    leakTouch(virgin.getRaw(), MsgPipeLeaker);

    virgin->sendSourceFinish();
}

// ClientHttpRequest tells us to abort
void ICAPClientReqmodPrecache::ownerAbort()
{
    debug(93,3)("ICAPClientReqmodPrecache::ownerAbort() called\n");
    stop(notifyIcap);
}

// ICAP client needs more virgin response data
void ICAPClientReqmodPrecache::noteSinkNeed(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSinkNeed() called\n");

    leakTouch(virgin.getRaw(), MsgPipeLeaker);

