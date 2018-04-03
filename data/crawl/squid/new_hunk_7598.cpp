    return (sent_user);
#endif /* USE_PROXY_AUTH */
}

int icpProcessExpired(fd, icpState)
     int fd;
     icpStateData *icpState;
{
    char *url = icpState->url;
    char *request_hdr = icpState->request_hdr;
    StoreEntry *entry = NULL;

    debug(33, 3, "icpProcessExpired: FD %d '%s'\n", fd, icpState->url);

    icpState->old_entry = icpState->entry;
    entry = storeCreateEntry(url,
	request_hdr,
	icpState->flags,
	icpState->method);
    /* NOTE, don't call storeLockObject(), storeCreateEntry() does it */

    entry->lastmod = icpState->old_entry->lastmod;
    debug(33, 5, "icpProcessExpired: setting lmt = %d\n",
	entry->lastmod);

    entry->refcount++;		/* MISS CASE */
    entry->mem_obj->fd_of_first_client = fd;
    icpState->entry = entry;
    icpState->offset = 0;
    /* Register with storage manager to receive updates when data comes in. */
    storeRegister(entry, fd, (PIF) icpHandleIMSReply, (void *) icpState);
    return (protoDispatch(fd, url, icpState->entry, icpState->request));
}


int icpHandleIMSReply(fd, entry, data)
     int fd;
     StoreEntry *entry;
     void *data;
{
    icpStateData *icpState = data;
    MemObject *mem = entry->mem_obj;
    LOCAL_ARRAY(char, hbuf, 8192);
    int len;
    debug(33, 0, "icpHandleIMSReply: FD %d '%s'\n", fd, entry->url);
    /* unregister this handler */
    storeUnregister(entry, fd);
    if (entry->store_status == STORE_ABORTED) {
	debug(33, 0, "icpHandleIMSReply: abort_code=%d\n",
	    entry->mem_obj->abort_code);
	icpSendERROR(fd,
	    entry->mem_obj->abort_code,
	    entry->mem_obj->e_abort_msg,
	    icpState,
	    400);
	return 0;
    }
    if (mem->reply->code == 304 && !BIT_TEST(icpState->flags, REQ_IMS)) {
	icpState->log_type = LOG_TCP_EXPIRED_HIT;
	/* We initiated the IMS request, the client is not expecting
	 * 304, so put the good one back */
	storeUnlockObject(entry);
	entry = icpState->entry = icpState->old_entry;
	/* Extend the TTL
	 * * XXX race condition here.  Assumes old_entry has been swapped 
	 * * in by the time this 304 reply arrives.  */
	storeClientCopy(entry, 0, 8191, hbuf, &len, fd);
	if (!mime_headers_end(hbuf))
	    fatal_dump("icpHandleIMSReply: failed to load headers, lost race");
	httpParseHeaders(hbuf, entry->mem_obj->reply);
	debug(44, 0, "OLD EXPIRES=%d\n", entry->expires);
	ttlSet(entry);
	debug(44, 0, "NEW EXPIRES=%d\n", entry->expires);
    } else {
	/* the client can handle this reply, whatever it is */
	icpState->log_type = LOG_TCP_EXPIRED_MISS;
	storeUnlockObject(icpState->old_entry);
    }
    /* done with old_entry */
    icpState->old_entry = NULL;
    /* switch the handler for incoming data */
    if (entry->store_status != STORE_OK)
	storeRegister(icpState->entry,
	    fd,
	    (PIF) icpHandleStore,
	    (void *) icpState);
    /* give it to the client */
    icpSendMoreData(fd, icpState);
    return 1;
}
