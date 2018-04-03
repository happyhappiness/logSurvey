     if (s->sslContextSessionId)
         storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);
 
-    if (s->generateHostCertificates)
-        storeAppendPrintf(e, " generate-host-certificates");
+    if (!s->generateHostCertificates)
+        storeAppendPrintf(e, " generate-host-certificates=off");
 
-    if (s->dynamicCertMemCacheSize != std::numeric_limits<size_t>::max())
-        storeAppendPrintf(e, "dynamic_cert_mem_cache_size=%lu%s\n", (unsigned long)s->dynamicCertMemCacheSize, B_BYTES_STR);
+    if (s->dynamicCertMemCacheSize != 4*1024*1024) // 4MB default
+        storeAppendPrintf(e, "dynamic_cert_mem_cache_size=%" PRIuSIZE "%s\n", s->dynamicCertMemCacheSize, B_BYTES_STR);
 #endif
 }
 