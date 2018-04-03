 }
 
 void
-storeAufsDirDump(StoreEntry * entry, const char *name, SwapDir * s)
+storeAufsDirDump(StoreEntry * entry, SwapDir * s)
 {
     aioinfo_t *aioinfo = (aioinfo_t *) s->fsdata;
-    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
-	name,
-	"aufs",
-	s->path,
+    storeAppendPrintf(entry, " %d %d %d",
 	s->max_size >> 10,
 	aioinfo->l1,
 	aioinfo->l2);
+    dump_cachedir_options(entry, options, s);
 }
 
 /*
