	     * call this reply a body, set the done_copying flag and
	     * continue...
	     */
	    /* RBC: Note that this is seriously broken, as we *need* the
	     * metadata to allow further client modules to work. As such 
	     * webservers are seriously broken, this is probably not 
	     * going to get fixed.. perhapos we should remove it?
	     */
	    debug (88,0)("Broken head response - probably phttpd/0.99.72\n");
	    http->flags.done_copying = 1;
	    flags.complete = 1;
	    
	    StoreIOBuffer tempBuffer;
	    assert(body_buf && body_size);
	    tempBuffer.length = body_size;
	    tempBuffer.data = body_buf;
	    clientStreamCallback((clientStreamNode *)http->client_stream.head->data, 
		http, NULL, tempBuffer);
    } else {
	debug (88,0)("clientReplyContext::sendMoreData: Unable to parse reply headers within a single HTTP_REQBUF_SZ length buffer\n");
	StoreIOBuffer tempBuffer;
	tempBuffer.flags.error = 1;
	sendStreamError(tempBuffer);
    }
    fatal ("clientReplyContext::sendMoreData: Unreachable code reached \n");
}

int
clientReplyBodyTooLarge(HttpReply const * rep, ssize_t clen)
{
    if (0 == rep->maxBodySize)
	return 0;		/* disabled */
