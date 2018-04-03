         certs.emplace_back(t);
     } else if (strncmp(token, "key=", 4) == 0) {
         if (certs.empty() || certs.back().certFile.isEmpty()) {
-            debugs(3, DBG_PARSE_NOTE(1), "ERROR: cert= option must be set before key= is used.");
+            fatal("cert= option must be set before key= is used.");
             return;
         }
         KeyData &t = certs.back();