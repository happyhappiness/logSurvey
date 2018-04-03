     else
         strListAdd(&strFwd, "unknown", ',');
 
-    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.c_str());
+    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
 
-    strFwd.clear();
+    strFwd.clean();
 
     /* append Host if not there already */
     if (!hdr_out->has(HDR_HOST)) {
