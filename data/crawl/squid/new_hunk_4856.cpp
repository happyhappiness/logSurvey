{
    adapted = NULL;	// refcounted
}

/*
 * Something that needs to read the adapated request body
 * calls this function, via the BodyReader class.  We copy
 * the body data from our bodybuf object to the BodyReader
 * MemBuf, which was passed as a reference to this function.
 */
size_t
ICAPClientReqmodPrecache::readBody(void *data, MemBuf &mb, size_t size)
{
    ICAPClientReqmodPrecache *icap = static_cast<ICAPClientReqmodPrecache *>(data);
    assert(icap != NULL);
    assert(icap->adapted != NULL);
    assert(icap->adapted->data != NULL);
    MemBuf *bodybuf = icap->adapted->data->body;
    assert(bodybuf != NULL);
    debugs(32,3,HERE << "readBody requested size " << size);
    debugs(32,3,HERE << "readBody bodybuf size " << bodybuf->contentSize());

    if ((mb_size_t) size > bodybuf->contentSize())
        size = bodybuf->contentSize();

    debugs(32,3,HERE << "readBody actual size " << size);

    assert(size);

    mb.append(bodybuf->content(), size);

    bodybuf->consume(size);

    return size;
}

void
ICAPClientReqmodPrecache::abortBody(void *data, size_t remaining)
{
    if (remaining >= 0) {
        debugs(0,0,HERE << "ICAPClientReqmodPrecache::abortBody size " << remaining);
        // more?
    }

    ICAPClientReqmodPrecache *icap = static_cast<ICAPClientReqmodPrecache *>(data);
    icap->stop(notifyIcap);
}

/*
 * Restart reading the adapted response from the ICAP server in case
 * the body buffer became full and we stopped reading.
 */
void
ICAPClientReqmodPrecache::kickBody(void *data)
{
    debugs(32,3,HERE << "ICAPClientReqmodPrecache::kickBody");
    ICAPClientReqmodPrecache *icap = static_cast<ICAPClientReqmodPrecache *>(data);
    assert(icap->adapted != NULL);
    icap->adapted->sendSinkNeed();
}
