 
             if (vary.buf()) {
                 /* Again, we own this structure layout */
-                ((HttpHeader) pe->getReply()->header).putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
+                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
                 vary.clean();
             }
 