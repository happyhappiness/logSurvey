 void
 storeAufsDirDump(StoreEntry * entry, const char *name, SwapDir * s)
 {
-    aioinfo_t *aioinfo = (aioinfo_t *)s->fsdata;
+    aioinfo_t *aioinfo = (aioinfo_t *) s->fsdata;
     storeAppendPrintf(entry, "%s %s %s %d %d %d\n",
 	name,
-        "asyncufs",
+	"asyncufs",
 	s->path,
 	s->max_size >> 10,
 	aioinfo->l1,
