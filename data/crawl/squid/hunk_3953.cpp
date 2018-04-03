 
             if (vary.size()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_VARY, vary.unsafeBuf());
+                rep->header.putStr(HDR_VARY, vary.termedBuf());
                 vary.clean();
             }
 
