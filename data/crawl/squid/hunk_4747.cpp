 
     mb.Printf("\r\n");
     debug(24, 6) ("waisSendRequest: buf: %s\n", mb.buf);
-    comm_old_write_mbuf(fd, &mb, waisSendComplete, waisState);
+    comm_write_mbuf(fd, &mb, waisSendComplete, waisState);
 
     if (EBIT_TEST(waisState->entry->flags, ENTRY_CACHABLE))
         storeSetPublicKey(waisState->entry);	/* Make it public */
