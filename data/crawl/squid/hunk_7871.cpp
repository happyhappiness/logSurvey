     }
     return 1;
 }
+#else
+int storeEntryValidLength(e)
+     StoreEntry *e;
+{
+    MemObject *mem = e->mem_obj;
+    int diff;
+
+    if (mem == NULL)
+	fatal_dump("storeEntryValidLength: NULL mem_obj");
+
+    debug(20, 3, "storeEntryValidLength: Checking '%s'\n", e->key);
+    debug(20, 3, "storeEntryValidLength:     object_len = %d\n", e->object_len);
+    debug(20, 3, "storeEntryValidLength:         hdr_sz = %d\n", mem->hdr_sz);
+    debug(20, 3, "storeEntryValidLength: content_length = %d\n", mem->content_length);
+
+    if (mem->content_length == 0) {
+	debug(20, 1, "storeEntryValidLength: Zero content length; assume valid; '%s'\n",
+	    e->key);
+	return 1;
+    }
+    if (mem->hdr_sz == 0) {
+	debug(20, 1, "storeEntryValidLength: Zero header size; assume valid; '%s'\n",
+	    e->key);
+	return 1;
+    }
+    diff = mem->hdr_sz + mem->content_length - e->object_len;
+    if (diff != 0) {
+	debug(20, 1, "storeEntryValidLength: %d bytes too %s; '%s'\n",
+	    diff < 0 ? -diff : diff,
+	    diff < 0 ? "small" : "big",
+	    e->key);
+	return 0;
+    }
+    return 1;
+}
+#endif
 
 static int storeVerifySwapDirs(clean)
      int clean;