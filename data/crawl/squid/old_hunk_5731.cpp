	storeAppendPrintf(s, "log_type %s\n", log_tags[http->log_type]);
	storeAppendPrintf(s, "out.offset %ld, out.size %lu\n",
	    (long int) http->out.offset, (unsigned long int) http->out.size);
	storeAppendPrintf(s, "req_sz %d\n", http->req_sz);
	e = http->entry;
	storeAppendPrintf(s, "entry %p/%s\n", e, e ? storeKeyText(e->hash.key) : "N/A");
	e = http->old_entry;
