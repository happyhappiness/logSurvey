        HttpRequest *req = dynamic_cast<HttpRequest*>(adapted->data->header);

        if (req) {
            debugs(93,3,HERE << "notifying body_reader, contentSize() = " << p->data->body->contentSize());
            req->body_reader->notify(p->data->body->contentSize());
        } else {
            http->takeAdaptedBody(adapted->data->body);
        }
    }
}

void ICAPClientReqmodPrecache::tellDoneAdapting()
{
    debug(93,3)("ICAPClientReqmodPrecache::tellDoneAdapting() called\n");
    //tell ClientHttpRequest that we expect no more response data
    http->doneAdapting(); // does not delete us (yet?)
    stop(notifyNone);
    // we should be eventually deleted by owner in ~ClientHttpRequest()
}

void ICAPClientReqmodPrecache::tellAbortAdapting()
{
    debug(93,3)("ICAPClientReqmodPrecache::tellAbortAdapting() called\n");
    // tell ClientHttpRequest that we are aborting ICAP processing prematurely
    http->abortAdapting();
}

// internal cleanup
void ICAPClientReqmodPrecache::stop(Notify notify)
{
    /*
     * NOTE: We do not clean up "adapted->sink" here because it may
     * have an HTTP message body that needs to stay around a little
     * while longer so that the HTTP server-side can forward it on.
     */

    // XXX: who will clean up the "adapted->sink" then? Does it happen
    // when the owner deletes us? Is that why we are deleted when the
    // owner is destroyed and not when ICAP adaptation is done, like
    // in http.cc case?

    // XXX: "adapted->sink" does not really have an "HTTP message body",
    // In fact, it simply points to "this". Should the above comment
    // refer to adapted and adapted->data->body?

    ICAPClientVector::clean(notify, false);
}

/*
