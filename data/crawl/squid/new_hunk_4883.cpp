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

