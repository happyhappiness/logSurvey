         storeAppendPrintf(s, "req_sz %ld\n", (long int) http->req_sz);
         e = http->storeEntry();
         storeAppendPrintf(s, "entry %p/%s\n", e, e ? e->getMD5Text() : "N/A");
-#if 0
-        /* Not a member anymore */
-        e = http->old_entry;
-        storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? e->getMD5Text() : "N/A");
-#endif
-
         storeAppendPrintf(s, "start %ld.%06d (%f seconds ago)\n",
                           (long int) http->start_time.tv_sec,
                           (int) http->start_time.tv_usec,