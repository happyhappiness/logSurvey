 
 #if USE_HTTP_VIOLATIONS
 static void
-dump_http_header_access(StoreEntry * entry, const char *name, header_mangler header[])
+dump_http_header_access(StoreEntry * entry, const char *name, const HeaderManglers *manglers)
 {
-    int i;
-
-    for (i = 0; i < HDR_ENUM_END; i++) {
-        if (header[i].access_list != NULL) {
-            storeAppendPrintf(entry, "%s ", name);
-            dump_acl_access(entry, httpHeaderNameById(i),
-                            header[i].access_list);
-        }
-    }
+    if (manglers)
+        manglers->dumpAccess(entry, name);
 }
 
 static void
-parse_http_header_access(header_mangler header[])
+parse_http_header_access(HeaderManglers **pm)
 {
-    int id, i;
     char *t = NULL;
 
     if ((t = strtok(NULL, w_space)) == NULL) {
