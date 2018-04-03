// ICAP client sends more data
void ICAPClientRespmodPrecache::noteSourceProgress(MsgPipe *p)
{
    debug(93,3)("ICAPClientRespmodPrecache::noteSourceProgress() called\n");
    //tell ServerStateData to store a fresh portion of the adapted response

    assert(serverState);

    if (p->data->body->hasContent()) {
        if (!serverState->takeAdaptedBody(p->data->body))
            return;

        // HttpStateData::takeAdaptedBody does not detect when we have enough,
        // so we always notify source that there more buffer space is available
        if (p->data->body->hasPotentialSpace())
            adapted->sendSinkNeed(); 
    }
}

void
ICAPClientRespmodPrecache::tellSpaceAvailable()
{
    serverState->icapSpaceAvailable();
}

void
ICAPClientRespmodPrecache::tellDoneAdapting()
{
    serverState->finishAdapting(); // deletes us
}

void
ICAPClientRespmodPrecache::tellAbortAdapting()
{
    debug(93,3)("ICAPClientReqmodPrecache::tellAbortAdapting() called\n");
    // tell ClientHttpRequest that we are aborting ICAP processing prematurely
    serverState->abortAdapting(); // deletes us
}

