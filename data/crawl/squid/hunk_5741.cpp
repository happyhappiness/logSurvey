 	    storeAppendPrintf(s, "\tnrequests: %d\n",
 		conn->nrequests);
 	    storeAppendPrintf(s, "\tdefer: n %d, until %ld\n",
-		conn->defer.n, (long int)conn->defer.until);
+		conn->defer.n, (long int) conn->defer.until);
 	}
 	storeAppendPrintf(s, "uri %s\n", http->uri);
 	storeAppendPrintf(s, "log_type %s\n", log_tags[http->log_type]);
 	storeAppendPrintf(s, "out.offset %ld, out.size %lu\n",
-	    (long int)http->out.offset, (unsigned long int)http->out.size);
+	    (long int) http->out.offset, (unsigned long int) http->out.size);
 	storeAppendPrintf(s, "req_sz %d\n", http->req_sz);
 	e = http->entry;
 	storeAppendPrintf(s, "entry %p/%s\n", e, e ? storeKeyText(e->hash.key) : "N/A");
 	e = http->old_entry;
 	storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? storeKeyText(e->hash.key) : "N/A");
 	storeAppendPrintf(s, "start %ld.%06d (%f seconds ago)\n",
-	    (long int)http->start.tv_sec,
-	    (int)http->start.tv_usec,
+	    (long int) http->start.tv_sec,
+	    (int) http->start.tv_usec,
 	    tvSubDsec(http->start, current_time));
 	storeAppendPrintf(s, "\n");
     }
