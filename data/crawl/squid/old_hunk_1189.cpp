    }
}

SQUIDCEXTERN CSR clientGetMoreData;
SQUIDCEXTERN CSS clientReplyStatus;
SQUIDCEXTERN CSD clientReplyDetach;

static ClientSocketContext *
parseHttpRequestAbort(ConnStateData * csd, const char *uri)
{
    ClientHttpRequest *http;
    ClientSocketContext *context;
    StoreIOBuffer tempBuffer;
    http = new ClientHttpRequest(csd);
    http->req_sz = csd->in.buf.length();
    http->uri = xstrdup(uri);
    setLogUri (http, uri);
    context = new ClientSocketContext(csd->clientConnection, http);
    tempBuffer.data = context->reqbuf;
    tempBuffer.length = HTTP_REQBUF_SZ;
    clientStreamInit(&http->client_stream, clientGetMoreData, clientReplyDetach,
