     if (!tempstr[0])
         return;
 
-    string strVary (rep->header.getList (HDR_VARY));
+    String strVary (rep->header.getList (HDR_VARY));
 
-    if (!strVary.size() || strVary[0] != '*') {
+    if (!strVary.size() || strVary.buf()[0] != '*') {
         rep->header.putStr (HDR_VARY, tempstr);
     }
 }
+
