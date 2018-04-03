         break;
 
     case 'H':
-        if (r) {
-            if (r->hier.host)
-                p = r->hier.host;
+        if (request) {
+            if (request->hier.host)
+                p = request->hier.host;
             else
-                p = r->GetHost();
+                p = request->GetHost();
         } else
             p = "[unknown host]";
 
         break;
 
     case 'i':
-        mb.Printf("%s", err->src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
+        mb.Printf("%s", src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
 
         break;
 
     case 'I':
-        if (r && r->hier.host) {
-            mb.Printf("%s", r->hier.host);
+        if (request && request->hier.host) {
+            mb.Printf("%s", request->hier.host);
         } else
             p = "[unknown]";
 
