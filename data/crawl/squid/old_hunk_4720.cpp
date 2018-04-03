        HttpRequest *req = dynamic_cast<HttpRequest*>(adapted->data->header);

        if (req) {
            debugs(32,3,HERE << "notifying body_reader, contentSize() = " << p->data->body->contentSize());
            req->body_reader->notify(p->data->body->contentSize());
        } else {
            http->takeAdaptedBody(adapted->data->body);
        }
    }
}

// ICAP client is done sending adapted response
void ICAPClientReqmodPrecache::noteSourceFinish(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceFinish() called\n");
    //tell ClientHttpRequest that we expect no more response data
    http->doneAdapting();
    stop(notifyNone);
}

// ICAP client is aborting
void ICAPClientReqmodPrecache::noteSourceAbort(MsgPipe *p)
{
    debug(93,3)("ICAPClientReqmodPrecache::noteSourceAbort() called\n");
    stop(notifyOwner);
}

// internal cleanup
void ICAPClientReqmodPrecache::stop(Notify notify)
{
    if (virgin != NULL) {
        if (notify == notifyIcap)
            virgin->sendSourceAbort();
        else
            virgin->source = NULL;

        freeVirgin();
    }

#if DONT_FREE_ADAPTED
    /*
     * NOTE: We do not clean up "adapted->sink" here because it may
     * have an HTTP message body that needs to stay around a little
     * while longer so that the HTTP server-side can forward it on.
     */
    if (adapted != NULL) {
        if (notify == notifyIcap)
            adapted->sendSinkAbort();
        else
            adapted->sink = NULL;

        freeAdapted();
    }

#endif

    if (http) {
        if (notify == notifyOwner)
            // tell ClientHttpRequest that we are aborting prematurely
            http->abortAdapting();

        cbdataReferenceDone(http);

        // http is now NULL, will not call it any more
    }
}

void ICAPClientReqmodPrecache::freeVirgin()
{
    // virgin->data->cause should be NULL;
    virgin = NULL;	// refcounted
}

void ICAPClientReqmodPrecache::freeAdapted()
{
    adapted = NULL;	// refcounted
}

/*
