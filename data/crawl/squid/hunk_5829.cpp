 }
 
 void
-storeDiskdDirDump(StoreEntry * entry, const char *name, SwapDir * s)
+storeDiskdDirDump(StoreEntry * entry, SwapDir * s)
 {
     diskdinfo_t *diskdinfo = s->fsdata;
-    storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
-	name,
-	"diskd",
-	s->path,
+    storeAppendPrintf(entry, " %d %d %d",
 	s->max_size >> 10,
 	diskdinfo->l1,
 	diskdinfo->l2);
+    dump_cachedir_options(entry, options, s);
 }
 
 /*
