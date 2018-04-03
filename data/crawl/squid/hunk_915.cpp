     if (s->dynamicCertMemCacheSize != std::numeric_limits<size_t>::max())
         storeAppendPrintf(e, "dynamic_cert_mem_cache_size=%lu%s\n", (unsigned long)s->dynamicCertMemCacheSize, B_BYTES_STR);
 #endif
+
+    if (!s->secure.sslFlags.isEmpty())
+        storeAppendPrintf(e, " tls-flags=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.sslFlags));
 }
 
 static void
