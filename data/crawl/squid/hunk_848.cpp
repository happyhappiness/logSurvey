             const int saved_id = page_id;
             page_id = ERR_SQUID_SIGNATURE;
             MemBuf *sign_mb = BuildContent();
-            mb.Printf("%s", sign_mb->content());
+            mb.append(sign_mb->content(), sign_mb->contentSize());
             sign_mb->clean();
             delete sign_mb;
             page_id = saved_id;
