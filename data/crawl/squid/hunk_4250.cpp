     case 'S':
         /* signature may contain %-escapes, recursion */
 
-        if (err->page_id != ERR_SQUID_SIGNATURE) {
-            const int saved_id = err->page_id;
-            err->page_id = ERR_SQUID_SIGNATURE;
-            MemBuf *sign_mb = errorBuildContent(err);
+        if (page_id != ERR_SQUID_SIGNATURE) {
+            const int saved_id = page_id;
+            page_id = ERR_SQUID_SIGNATURE;
+            MemBuf *sign_mb = BuildContent();
             mb.Printf("%s", sign_mb->content());
             sign_mb->clean();
             delete sign_mb;
-            err->page_id = saved_id;
+            page_id = saved_id;
             do_quote = 0;
         } else {
             /* wow, somebody put %S into ERR_SIGNATURE, stop recursion */
