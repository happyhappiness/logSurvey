	return 0;
    }
    if (mem->reply->code == 304 && !BIT_TEST(icpState->request->flags, REQ_IMS)) {
	/* We initiated the IMS request, the client is not expecting
	 * 304, so put the good one back.  First, make sure the old entry
	 * headers have been loaded from disk. */
	oldentry = icpState->old_entry;
	if (oldentry->mem_obj->e_current_len == 0) {
	    storeRegister(entry,
		fd,
		(PIF) icpHandleIMSReply,
		(void *) icpState);
	    return 0;
	}
	icpState->log_type = LOG_TCP_EXPIRED_HIT;
	hbuf = get_free_8k_page();
	storeClientCopy(oldentry, 0, 8191, hbuf, &len, fd);
	if (oldentry->mem_obj->request == NULL) {
	    oldentry->mem_obj->request = requestLink(mem->request);
	    unlink_request = 1;
	}
	storeUnlockObject(entry);
	entry = icpState->entry = oldentry;
	if (mime_headers_end(hbuf)) {
	    httpParseHeaders(hbuf, entry->mem_obj->reply);
	    ttlSet(entry);
	} else {
	    debug(33,1,"icpHandleIMSReply: No end-of-headers, len=%d\n", len);
	    debug(33,1,"  --> '%s'\n", entry->url);
	}
	put_free_8k_page(hbuf);
	if (unlink_request) {
	    requestUnlink(entry->mem_obj->request);
	    entry->mem_obj->request = NULL;