    return 1;
}

clientSocketContext *
connGetCurrentContext(ConnStateData * conn)
{
    assert(conn);
    return (clientSocketContext *)conn->currentobject;
}

void
contextDeferRecipientForLater(clientSocketContext * context, clientStreamNode * node, HttpReply * rep, StoreIOBuffer recievedData)
{
    debug(33, 2) ("clientSocketRecipient: Deferring %s\n", context->http->uri);
    assert(context->flags.deferred == 0);
    context->flags.deferred = 1;
    context->deferredparams.node = node;
    context->deferredparams.rep = rep;
    context->deferredparams.queuedBuffer = recievedData;
    return;
}

int
responseFinishedOrFailed(HttpReply * rep, StoreIOBuffer recievedData)
{
    if (rep == NULL && recievedData.data == NULL && recievedData.length == 0)
	return 1;
    return 0;
}

int
contextStartOfOutput(clientSocketContext * context)
{
    return context->http->out.size == 0 ? 1 : 0;
}

void
contextSendBody(clientSocketContext * context, HttpReply * rep, StoreIOBuffer bodyData)
{
    assert(rep == NULL);
    context->http->out.offset += bodyData.length;
    comm_write(context->http->conn->fd, bodyData.data, bodyData.length,
	clientWriteBodyComplete, context);
    return;
}

void
contextSendStartOfMessage(clientSocketContext * context, HttpReply * rep, StoreIOBuffer bodyData)
{
    MemBuf mb;
    /* write headers and/or body if any */
    assert(rep || (bodyData.data && bodyData.length));
    /* init mb; put status line and headers if any */
    if (rep) {
	mb = httpReplyPack(rep);
	/* Save length of headers for persistent conn checks */
	context->http->out.headers_sz = mb.size;
#if HEADERS_LOG
	headersLog(0, 0, context->http->request->method, rep);
#endif
	httpReplyDestroy(rep);
	rep = NULL;
    } else {
	memBufDefInit(&mb);
    }
    if (bodyData.data && bodyData.length) {
	context->http->out.offset += bodyData.length;
	memBufAppend(&mb, bodyData.data, bodyData.length);
    }
    /* write */
    comm_old_write_mbuf(context->http->conn->fd, mb, clientWriteComplete, context);
    /* if we don't do it, who will? */
}

