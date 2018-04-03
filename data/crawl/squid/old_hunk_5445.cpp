	     * call this reply a body, set the done_copying flag and
	     * continue...
	     */
	    http->flags.done_copying = 1;
	    context->flags.complete = 1;
	}
    } {
	StoreIOBuffer tempBuffer = EMPTYIOBUFFER;
	assert(rep || (body_buf && body_size));
	tempBuffer.length = body_size;
	tempBuffer.data = body_buf;
	/* TODO: move the data in the buffer back by the request header size */
	clientStreamCallback((clientStreamNode *)http->client_stream.head->data, http, rep,
	    tempBuffer);
    }
}

int
clientReplyBodyTooLarge(HttpReply * rep, ssize_t clen)
{
    if (0 == rep->maxBodySize)
	return 0;		/* disabled */
