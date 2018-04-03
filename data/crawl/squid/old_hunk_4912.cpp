}

// ClientHttpRequest says we have the entire HTTP message
void ICAPClientSideHook::doneSending()
{
    debug(93,3)("ICAPClientSideHook::doneSending() called\n");
    leakTouch(virgin.getRaw(), MsgPipeLeaker);

    virgin->sendSourceFinish();
}

// ClientHttpRequest tells us to abort
void ICAPClientSideHook::ownerAbort()
{
    debug(93,3)("ICAPClientSideHook::ownerAbort() called\n");
    stop(notifyIcap);
}

// ICAP client needs more virgin response data
void ICAPClientSideHook::noteSinkNeed(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSinkNeed() called\n");

    leakTouch(virgin.getRaw(), MsgPipeLeaker);

