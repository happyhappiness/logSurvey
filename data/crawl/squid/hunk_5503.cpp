     MemObject *mem = e->mem_obj;
     int i;
     dlink_node *node;
-    storeAppendPrintf(s, "KEY %s\n", storeKeyText((const cache_key *)e->hash.key));
+    storeAppendPrintf(s, "KEY %s\n", e->getMD5Text());
     if (mem)
 	storeAppendPrintf(s, "\t%s %s\n",
 	    RequestMethodStr[mem->method], mem->log_url);
