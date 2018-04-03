}

// HttpStateData tells us to abort
void ICAPClientRespmodPrecache::ownerAbort()
{
    debug(93,5)("ICAPClientRespmodPrecache::ownerAbort() called\n");
    stop(notifyIcap);
}

// ICAP client needs more virgin response data
void ICAPClientRespmodPrecache::noteSinkNeed(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSinkNeed() called\n");

    leakTouch(virgin.getRaw(), MsgPipeLeaker);

