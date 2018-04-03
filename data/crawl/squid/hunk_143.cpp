     if (it != TheSslErrorShortcuts.end()) {
         // Should not be empty...
         assert(it->second[0] != SSL_ERROR_NONE);
-        Ssl::Errors *errors = new Ssl::Errors(it->second[0]);
-        for (int i =1; it->second[i] != SSL_ERROR_NONE; ++i) {
-            errors->push_back_unique(it->second[i]);
+        for (int i = 0; it->second[i] != SSL_ERROR_NONE; ++i) {
+            errors.emplace(it->second[i]);
         }
-        return errors;
+        return true;
     }
 
-    fatalf("Unknown SSL error name '%s'", name);
-    return NULL; // not reached
+    fatalf("Unknown TLS error name '%s'", name);
+    return false; // not reached
 }
 
 const char *Ssl::GetErrorName(Security::ErrorCode value)
