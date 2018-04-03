	kb_incr(&statCounter.client_http.hit_kbytes_out, size);
}

void
clientPullData(clientSocketContext * context)
{
    /* More data will be coming from the stream. */
    StoreIOBuffer readBuffer = EMPTYIOBUFFER;
    readBuffer.offset = context->http->out.offset;
    readBuffer.length = HTTP_REQBUF_SZ;
    readBuffer.data = context->reqbuf;
    clientStreamRead(getTail(context), context->http, readBuffer);
}

/* A write has just completed to the client, or we have just realised there is
