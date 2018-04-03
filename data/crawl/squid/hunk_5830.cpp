 }
 
 void
-storeUfsDirDump(StoreEntry * entry, const char *name, SwapDir * s)
+storeUfsDirDump(StoreEntry * entry, SwapDir * s)
 {
     ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
-    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
-	name,
-	"ufs",
-	s->path,
+    storeAppendPrintf(entry, " %d %d %d",
 	s->max_size >> 10,
 	ufsinfo->l1,
 	ufsinfo->l2);
+    dump_cachedir_options(entry, options, s);
 }
 
 /*
