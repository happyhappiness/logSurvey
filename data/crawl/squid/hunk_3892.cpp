 #if X_ACCELERATOR_VARY
             vary = mem_obj->getReply()->header.getList(HDR_X_ACCELERATOR_VARY);
 
-            if (vary.unsafeBuf()) {
+            if (vary.defined()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.unsafeBuf());
+                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.termedBuf());
                 vary.clean();
             }
 