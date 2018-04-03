 dump_http_header_access(StoreEntry * entry, const char *name, header_mangler header[])
 {
     int i;
-    storeAppendPrintf(entry, "%s:", name);
     for (i = 0; i < HDR_ENUM_END; i++) {
 	if (header[i].access_list != NULL) {
-	    storeAppendPrintf(entry, "\t");
+	    storeAppendPrintf(entry, "%s ",name);
 	    dump_acl_access(entry, httpHeaderNameById(i),
 		header[i].access_list);
 	}
