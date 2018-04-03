void ICAPClientRespmodPrecache::noteSourceProgress(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSourceProgress() called\n");
    //tell HttpStateData to store a fresh portion of the adapted response

    if (p->data->body->hasContent()) {
        httpState->takeAdaptedBody(p->data->body);
    }
}

// ICAP client is done sending adapted response
void ICAPClientRespmodPrecache::noteSourceFinish(MsgPipe *p)
{
    debug(93,5)("ICAPClientRespmodPrecache::noteSourceFinish() called\n");
    //tell HttpStateData that we expect no more response data
    httpState->doneAdapting();
    stop(notifyNone);
}

