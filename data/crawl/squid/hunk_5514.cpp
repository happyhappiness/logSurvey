     storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
 }
 
-int
+http_hdr_type
 httpHeaderIdByName(const char *name, int name_len, const HttpHeaderFieldInfo * info, int end)
 {
     int i;
