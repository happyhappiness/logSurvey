     int i;
     struct _store_client *sc;
     dlink_node *node;
-    storeAppendPrintf(s, "KEY %s\n", storeKeyText(e->key));
+    storeAppendPrintf(s, "KEY %s\n", storeKeyText(e->hash.key));
     if (mem)
 	storeAppendPrintf(s, "\t%s %s\n",
 	    RequestMethodStr[mem->method], mem->log_url);
