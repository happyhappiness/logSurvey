     else
         strListAdd(&strFwd, "unknown", ',');
 
-    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
+    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.c_str());
 
-    strFwd.clean();
+    strFwd.clear();
 
     /* append Host if not there already */
     if (!hdr_out->has(HDR_HOST)) {
