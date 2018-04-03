 #if X_ACCELERATOR_VARY
             vary = mem_obj->getReply()->header.getList(HDR_X_ACCELERATOR_VARY);
 
-            if (vary.buf()) {
+            if (vary.unsafeBuf()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
+                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.unsafeBuf());
                 vary.clean();
             }
 