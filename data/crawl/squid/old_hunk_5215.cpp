     */
}

/* Detach from a buffering stream
 */
void
esiBufferDetach (clientStreamNode *node, clientHttpRequest *http)
{
    /* Detach ourselves */
    clientStreamDetach (node, http);
}

/*
 * Write a chunk of data to a client 'socket'. 
 * If the reply is present, send the reply headers down the wire too,
 * and clean them up when finished.
 * Pre-condition: 
 *   The request is an internal ESI subrequest.
 *   data context is not NULL
 *   There are no more entries in the stream chain.
 */
void
esiBufferRecipient (clientStreamNode *node, clientHttpRequest *http, HttpReply *rep, StoreIOBuffer recievedData)
{
    /* Test preconditions */
    assert (node != NULL);
    /* ESI TODO: handle thisNode rather than asserting
     * - it should only ever happen if we cause an 
     * abort and the callback chain loops back to 
     * here, so we can simply return. However, that 
     * itself shouldn't happen, so it stays as an 
     * assert for now. */
    assert (cbdataReferenceValid (node));
    assert (node->node.next == NULL);
    assert (http->conn == NULL);

    esiStreamContext::Pointer esiStream = dynamic_cast<esiStreamContext *>(node->data.getRaw());
    assert (esiStream.getRaw() != NULL);
    /* If segments become more flexible, ignore thisNode */
    assert (recievedData.length <= sizeof(esiStream->localbuffer->buf));
    assert (!esiStream->finished);

    debug (86,5) ("esiBufferRecipient rep %p body %p len %d\n", rep, recievedData.data, recievedData.length);
    assert (node->readBuffer.offset == recievedData.offset || recievedData.length == 0);

    /* trivial case */

    if (http->out.offset != 0) {
        assert(rep == NULL);
    } else {
        if (rep) {
            if (rep->sline.status != HTTP_OK) {
                httpReplyDestroy(rep);
                rep = NULL;
                esiStream->include->fail (esiStream);
                esiStream->finished = 1;
                httpRequestFree (http);
                return;
            }

#if HEADERS_LOG
            /* should be done in the store rather than every recipient?  */
            headersLog(0, 0, http->request->method, rep);

#endif

            httpReplyDestroy(rep);

            rep = NULL;
        }
    }

    if (recievedData.data && recievedData.length) {
        http->out.offset += recievedData.length;

        if (recievedData.data >= esiStream->localbuffer->buf &&
                recievedData.data < &esiStream->localbuffer->buf[sizeof(esiStream->localbuffer->buf)]) {
            /* original static buffer */

            if (recievedData.data != esiStream->localbuffer->buf) {
                /* But not the start of it */
                xmemmove (esiStream->localbuffer->buf, recievedData.data, recievedData.length);
            }

            esiStream->localbuffer->len = recievedData.length;
        } else {
            assert (esiStream->buffer.getRaw() != NULL);
            esiStream->buffer->len = recievedData.length;
        }
    }

    /* EOF / Read error /  aborted entry */
    if (rep == NULL && recievedData.data == NULL && recievedData.length == 0) {
        /* TODO: get stream status to test the entry for aborts */
        debug (86,5)("Finished reading upstream data in subrequest\n");
        esiStream->include->subRequestDone (esiStream, true);
        esiStream->finished = 1;
        httpRequestFree (http);
        return;
    }


    /* after the write to the user occurs, (ie here, or in a callback)
     * we call */
    if (clientHttpRequestStatus(-1, http)) {
        /* TODO: Does thisNode if block leak htto ? */
        /* XXX when reviewing ESI this is the first place to look */
        node->data = NULL;
        esiStream->finished = 1;
        esiStream->include->fail (esiStream);
        return;
    };

    switch (clientStreamStatus (node, http)) {

    case STREAM_UNPLANNED_COMPLETE: /* fallthru ok */

    case STREAM_COMPLETE: /* ok */
        debug (86,3)("ESI subrequest finished OK\n");
        esiStream->include->subRequestDone (esiStream, true);
        esiStream->finished = 1;
        httpRequestFree (http);
        return;

    case STREAM_FAILED:
        debug (86,1)("ESI subrequest failed transfer\n");
        esiStream->include->fail (esiStream);
        esiStream->finished = 1;
        httpRequestFree (http);
        return;

    case STREAM_NONE: {
            StoreIOBuffer tempBuffer;

            if (!esiStream->buffer.getRaw()) {
                esiStream->buffer = esiStream->localbuffer;
            }

            esiStream->buffer = esiStream->buffer->tail();

            if (esiStream->buffer->len) {
                esiStream->buffer->next = new ESISegment;
                esiStream->buffer = esiStream->buffer->next;
            }

            tempBuffer.offset = http->out.offset;
            tempBuffer.length = sizeof (esiStream->buffer->buf);
            tempBuffer.data = esiStream->buffer->buf;
            /* now just read into 'buffer' */
            clientStreamRead (node,
                              http, tempBuffer);
            debug (86,5)("esiBufferRecipient: Requested more data for ESI subrequest\n");
        }

        break;

    default:
        fatal ("Hit unreachable code in esiBufferRecipient\n");
    }

}

/* esiStream functions */
ESIStreamContext::~ESIStreamContext()
{
    assert (this);
    freeResources();
}

void
ESIStreamContext::freeResources()
{
    debug (86,5)("Freeing stream context resources.\n");
    buffer = NULL;
    localbuffer = NULL;
    include = NULL;
}

void *
ESIStreamContext::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (ESIStreamContext));
    CBDATA_INIT_TYPE(ESIStreamContext);
    ESIStreamContext *result = cbdataAlloc(ESIStreamContext);
    /* Mark result as being owned - we want the refcounter to do the
     * delete call
     */
    cbdataReference(result);
    return result;
}

void
ESIStreamContext::operator delete (void *address)
{
    ESIStreamContext *t = static_cast<ESIStreamContext *>(address);
    cbdataFree(t);
    /* And allow the memory to be freed */
    cbdataReferenceDone (address);
}

void
ESIStreamContext::deleteSelf() const
{
    delete this;
}

esiStreamContext *
esiStreamContextNew (esiIncludePtr include)
{
    esiStreamContext *rv = new ESIStreamContext;
    rv->include = include;
    return rv;
}

/* Implementation of ESIElements */

/* esiComment */
