     if (!tempstr[0])
         return;
 
-    String strVary (httpHeaderGetList (&rep->header, HDR_VARY));
+    String strVary (rep->header.getList (HDR_VARY));
 
     if (!strVary.size() || strVary.buf()[0] != '*') {
-        httpHeaderPutStr (&rep->header, HDR_VARY, tempstr);
+        rep->header.putStr (HDR_VARY, tempstr);
     }
 }
 