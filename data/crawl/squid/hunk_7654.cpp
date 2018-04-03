     LOCAL_ARRAY(char, abort_msg, 2000);
     MemObject *mem = e->mem_obj;
 
+    if (mem == NULL)		/* XXX remove later */
+	fatal_dump("storeAbort: null mem");
+
     debug(20, 6, "storeAbort: '%s'\n", e->key);
     e->expires = squid_curtime + Config.negativeTtl;
     e->store_status = STORE_ABORTED;
