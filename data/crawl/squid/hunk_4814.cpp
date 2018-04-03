 
             if (vary.size()) {
                 /* Again, we own this structure layout */
-                ((HttpHeader) pe->getReply()->header).putStr(HDR_VARY, vary.buf());
+                rep->header.putStr(HDR_VARY, vary.buf());
                 vary.clean();
             }
 
