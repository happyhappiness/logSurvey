 void
 storeUfsDirDump(StoreEntry * entry, const char *name, SwapDir * s)
 {
-    ufsinfo_t *ufsinfo = (ufsinfo_t *)s->fsdata;
+    ufsinfo_t *ufsinfo = (ufsinfo_t *) s->fsdata;
     storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
 	name,
-        "ufs",
+	"ufs",
 	s->path,
 	s->max_size >> 10,
 	ufsinfo->l1,
