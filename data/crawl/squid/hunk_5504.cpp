 	    (long int) http->out.offset, (unsigned long int) http->out.size);
 	storeAppendPrintf(s, "req_sz %ld\n", (long int) http->req_sz);
 	e = http->entry;
-	storeAppendPrintf(s, "entry %p/%s\n", e, e ? storeKeyText((cache_key const *)e->hash.key) : "N/A");
+	storeAppendPrintf(s, "entry %p/%s\n", e, e ? e->getMD5Text() : "N/A");
 	e = http->old_entry;
-	storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? storeKeyText((cache_key const *)e->hash.key) : "N/A");
+	storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? e->getMD5Text() : "N/A");
 	storeAppendPrintf(s, "start %ld.%06d (%f seconds ago)\n",
 	    (long int) http->start.tv_sec,
 	    (int) http->start.tv_usec,
