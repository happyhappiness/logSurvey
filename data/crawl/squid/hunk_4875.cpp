         break;
 
     case 'I':
-        if (err->host) {
-            mb.Printf("%s", err->host);
+        if (r && r->hier.host) {
+            mb.Printf("%s", r->hier.host);
         } else
             p = "[unknown]";
 
