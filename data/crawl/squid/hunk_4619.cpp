 
         if (mem_obj->vary_headers && !storeGetPublic(mem_obj->url, mem_obj->method)) {
             /* Create "vary" base object */
-            String vary;
+            string vary;
             StoreEntry *pe = storeCreateEntry(mem_obj->url, mem_obj->log_url, request->flags, request->method);
             HttpVersion version(1, 0);
             /* We are allowed to do this typecast */
             HttpReply *rep = new HttpReply;
             rep->setHeaders(version, HTTP_OK, "Internal marker object", "x-squid-internal/vary", -1, -1, squid_curtime + 100000);
             vary = mem_obj->getReply()->header.getList(HDR_VARY);
 
-            if (vary.size()) {
+            if (!vary.empty()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_VARY, vary.buf());
-                vary.clean();
+                rep->header.putStr(HDR_VARY, vary.c_str());
+                vary.clear();
             }
 
 #if X_ACCELERATOR_VARY
             vary = mem_obj->getReply()->header.getList(HDR_X_ACCELERATOR_VARY);
 
-            if (vary.buf()) {
+            if (!vary.empty()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
-                vary.clean();
+                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.c_str());
+                vary.clear();
             }
 
 #endif
