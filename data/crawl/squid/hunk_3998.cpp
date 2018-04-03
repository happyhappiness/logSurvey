 
             if (vary.size()) {
                 /* Again, we own this structure layout */
-                rep->header.putStr(HDR_VARY, vary.buf());
+                rep->header.putStr(HDR_VARY, vary.unsafeBuf());
                 vary.clean();
             }
 
