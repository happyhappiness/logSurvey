}

// ICAP client is done sending adapted response
void ICAPClientSideHook::noteSourceFinish(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSourceFinish() called\n");
    //tell ClientHttpRequest that we expect no more response data
    leakTouch(p, MsgPipeLeaker);
    http->doneAdapting();
    stop(notifyNone);
}

// ICAP client is aborting
void ICAPClientSideHook::noteSourceAbort(MsgPipe *p)
{
    debug(93,3)("ICAPClientSideHook::noteSourceAbort() called\n");
    leakTouch(p, MsgPipeLeaker);
    stop(notifyOwner);
}

// internal cleanup
void ICAPClientSideHook::stop(Notify notify)
{
    if (virgin != NULL) {
        leakTouch(virgin.getRaw(), MsgPipeLeaker);
