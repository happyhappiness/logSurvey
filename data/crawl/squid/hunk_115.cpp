     return NULL;
 }
 
+Auth::Config *
+Auth::Config::GetParsed(const char *proxy_auth)
+{
+    if (auto *cfg = Find(proxy_auth))
+        return cfg;
+    fatalf("auth_schemes: required authentication method '%s' is not configured", proxy_auth);
+    return nullptr;
+}
+
 /** Default behaviour is to expose nothing */
 void
 Auth::Config::registerWithCacheManager(void)
