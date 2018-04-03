 {
     MemObject *mem = e->mem_obj;
     int i;
-    struct _store_client *sc;
     dlink_node *node;
     storeAppendPrintf(s, "KEY %s\n", storeKeyText(e->hash.key));
     if (mem)
