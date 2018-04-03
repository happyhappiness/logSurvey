 }
 
 void
-storeCossDirDump(StoreEntry * entry, const char *name, SwapDir * s)
+storeCossDirDump(StoreEntry * entry, SwapDir * s)
 {
-    storeAppendPrintf(entry, "%s %s %s %d\n",
-	name,
-	s->type,
-	s->path,
+    storeAppendPrintf(entry, " %d",
 	s->max_size >> 20);
+    dump_cachedir_options(entry, NULL, sd);
 }
 
 #if OLD_UNUSED_CODE
