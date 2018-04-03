// ICAP client sends more data
void ICAPClientRespmodPrecache::noteSourceProgress(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSourceProgress() called\n");
    //tell ServerStateData to store a fresh portion of the adapted response

    assert(serverState);

    if (p->data->body->hasContent()) {
        serverState->takeAdaptedBody(p->data->body);
    }
}

// ICAP client is done sending adapted response
void ICAPClientRespmodPrecache::noteSourceFinish(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSourceFinish() called\n");
    //tell ServerStateData that we expect no more response data
    serverState->doneAdapting();
    stop(notifyNone);
}

// ICAP client is aborting
void ICAPClientRespmodPrecache::noteSourceAbort(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSourceAbort() called\n");
    stop(notifyOwner);
}

// internal cleanup
void ICAPClientRespmodPrecache::stop(Notify notify)
{
    if (virgin != NULL) {
        if (notify == notifyIcap)
            virgin->sendSourceAbort();
        else
            virgin->source = NULL;

        freeVirgin();
    }

    if (adapted != NULL) {
        if (notify == notifyIcap)
            adapted->sendSinkAbort();
        else
            adapted->sink = NULL;

        freeAdapted();
    }

    if (serverState) {
        if (notify == notifyOwner)
            // tell ServerStateData that we are aborting prematurely
            serverState->abortAdapting();

        cbdataReferenceDone(serverState);

        // serverState is now NULL, will not call it any more
    }
}

void ICAPClientRespmodPrecache::freeVirgin()
{
    virgin = NULL;	// refcounted
}

void ICAPClientRespmodPrecache::freeAdapted()
{
    adapted = NULL;	// refcounted
}
