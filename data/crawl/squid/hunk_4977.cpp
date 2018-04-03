 
     case 'p':
         if (r) {
-            memBufPrintf(&mb, "%d", (int) r->port);
+            mb.Printf("%d", (int) r->port);
         } else {
             p = "[unknown port]";
         }
