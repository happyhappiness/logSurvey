     LOCAL_ARRAY(char, abort_msg, 2000);
     MemObject *mem = e->mem_obj;
 
+    if (e->store_status != STORE_PENDING)	/* XXX remove later */
+	fatal_dump("storeAbort: bad store_status");
     if (mem == NULL)		/* XXX remove later */
 	fatal_dump("storeAbort: null mem");
 
