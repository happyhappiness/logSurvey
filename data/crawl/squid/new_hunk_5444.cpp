	kb_incr(&statCounter.client_http.hit_kbytes_out, size);
}

/* returns true if there is still data available to pack more ranges
 * increments iterator "i"
 * used by clientPackMoreRanges */
bool
ClientSocketContext::canPackMoreRanges() const
{
    /* first update "i" if needed */
    if (!http->range_iter.debt()) {
	debug (33,5)("ClientSocketContext::canPackMoreRanges: At end of current range spec for fd %d\n",fd());
	if (http->range_iter.pos.incrementable())
	    ++http->range_iter.pos;
	http->range_iter.updateSpec();
    }
    assert(!http->range_iter.debt() == !http->range_iter.currentSpec());
    /* paranoid sync condition */
    /* continue condition: need_more_data */
    debug (33,5)("ClientSocketContext::canPackMoreRanges: returning %d\n", http->range_iter.currentSpec() ? true : false);
    return http->range_iter.currentSpec() ? true : false;
}

off_t
ClientSocketContext::getNextRangeOffset() const
{
    if (http->request->range) {
	/* offset in range specs does not count the prefix of an http msg */
	debug (0,0) ("ClientSocketContext::getNextRangeOffset: http offset %lu\n", http->out.offset);
	/* check: reply was parsed and range iterator was initialized */
	assert(http->range_iter.valid);
	/* filter out data according to range specs */
	assert (canPackMoreRanges());
	  {
	    off_t start;		/* offset of still missing data */
	    assert(http->range_iter.currentSpec());
	    start = http->range_iter.currentSpec()->offset + http->range_iter.currentSpec()->length - http->range_iter.debt();
	    debug(33, 3) ("clientPackMoreRanges: in:  offset: %ld\n",
			  (long int) http->out.offset);
	    debug(33, 3) ("clientPackMoreRanges: out: start: %ld spec[%ld]: [%ld, %ld), len: %ld debt: %ld\n",
			  (long int) start, (long int) (http->range_iter.pos - http->request->range->begin()), (long int) http->range_iter.currentSpec()->offset, (long int) (http->range_iter.currentSpec()->offset + http->range_iter.currentSpec()->length), (long int) http->range_iter.currentSpec()->length, (long int) http->range_iter.debt());
	    if (http->range_iter.currentSpec()->length != -1)
	    assert(http->out.offset <= start);	/* we did not miss it */
	    return start;
	}
#if 0
    } else if (http->request->range->specs.count > 1) {
	/* put terminating boundary for multiparts */
	clientPackTermBound(i->boundary, mb);
#endif
    }

    return http->out.offset;
}

void
ClientSocketContext::pullData()
{
    debug (33,5)("ClientSocketContext::pullData: FD %d attempting to pull upstream data\n", fd());
    /* More data will be coming from the stream. */
    StoreIOBuffer readBuffer;
    /* XXX: Next requested byte in the range sequence */
    /* XXX: length = getmaximumrangelenfgth */
    readBuffer.offset = getNextRangeOffset();
    readBuffer.length = HTTP_REQBUF_SZ;
    readBuffer.data = reqbuf;
    /* we may note we have reached the end of the wanted ranges */
    clientStreamRead(getTail(), http, readBuffer);
}

clientStream_status_t 
ClientSocketContext::socketState()
{
    switch (clientStreamStatus(getTail(), http)) {
      case STREAM_NONE:
        /* check for range support ending */
        if (http->request->range) {
	    /* check: reply was parsed and range iterator was initialized */
	    assert(http->range_iter.valid);
	    /* filter out data according to range specs */
	    if (!canPackMoreRanges()) {
		debug (33,5)("ClientSocketContext::socketState: Range request has hit end of returnable range sequence on fd %d\n", fd());
		if (http->request->flags.proxy_keepalive)
		    return STREAM_COMPLETE;
	        else
		    return STREAM_UNPLANNED_COMPLETE;
	    }
	}
	return STREAM_NONE;
      case STREAM_COMPLETE:
        return STREAM_COMPLETE;
      case STREAM_UNPLANNED_COMPLETE:
	return STREAM_UNPLANNED_COMPLETE;
      case STREAM_FAILED:
	return STREAM_FAILED;
    }
    fatal ("unreachable code\n");
    return STREAM_NONE;
}

/* A write has just completed to the client, or we have just realised there is
