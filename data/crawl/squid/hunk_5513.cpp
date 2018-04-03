     storeAppendPrintf(e, "\nHttp Fields Stats (replies and requests)\n");
     storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
 	"id", "name", "#alive", "%err", "%repeat");
-    for (ht = 0; ht < HDR_ENUM_END; ht++) {
+    for (ht = (http_hdr_type)0; ht < HDR_ENUM_END; ++ht) {
 	HttpHeaderFieldInfo *f = Headers + ht;
 	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
 	    f->id, strBuf(f->name), f->stat.aliveCount,
