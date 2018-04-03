}

// HttpStateData tells us to abort
void ICAPAnchor::ownerAbort()
{
    debug(93,5)("ICAPAnchor::ownerAbort() called\n");
    stop(notifyIcap);
}

// ICAP client needs more virgin response data
void ICAPAnchor::noteSinkNeed(MsgPipe *p)
{
    debug(93,5)("ICAPAnchor::noteSinkNeed() called\n");

    leakTouch(virgin.getRaw(), MsgPipeLeaker);

