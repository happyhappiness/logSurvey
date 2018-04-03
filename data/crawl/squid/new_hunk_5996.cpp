    if (EBIT_TEST(e->flags, ENTRY_DONT_LOG))
	return;
    if (mem != NULL) {
	if (mem->log_url == NULL) {
	    debug(20, 1) ("storeLog: NULL log_url for %s\n", mem->url);
	    storeMemObjectDump(mem);
	    mem->log_url = xstrdup(mem->url);
	}
	reply = mem->reply;
	/*
	 * XXX Ok, where should we print the dir number here?
	 * Because if we print it before the swap file number, it'll break
	 * the existing log format.
	 */
	logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X %s %4d %9d %9d %9d %s %d/%d %s %s\n",
	    (int) current_time.tv_sec,
	    (int) current_time.tv_usec / 1000,
	    storeLogTags[tag],
	    e->swap_dirn,
	    e->swap_filen,
	    storeKeyText(e->key),
	    reply->sline.status,
	    (int) reply->date,
	    (int) reply->last_modified,
	    (int) reply->expires,
	    strLen(reply->content_type) ? strBuf(reply->content_type) : "unknown",
	    reply->content_length,
	    (int) (mem->inmem_hi - mem->reply->hdr_sz),
	    RequestMethodStr[mem->method],
	    mem->log_url);
    } else {
	/* no mem object. Most RELEASE cases */
	logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X %s   ?         ?         ?         ? ?/? ?/? ? ?\n",
