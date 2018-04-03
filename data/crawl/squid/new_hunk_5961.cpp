	    http->out.offset, http->out.size);
	storeAppendPrintf(s, "req_sz %d\n", http->req_sz);
	e = http->entry;
	storeAppendPrintf(s, "entry %p/%s\n", e, e ? storeKeyText(e->hash.key) : "N/A");
	e = http->old_entry;
	storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? storeKeyText(e->hash.key) : "N/A");
	storeAppendPrintf(s, "start %d.%06d (%f seconds ago)\n", http->start.tv_sec,
	    http->start.tv_usec,
	    tvSubDsec(http->start, current_time));
