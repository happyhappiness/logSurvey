 #if USE_OPENSSL
     if (s->flags.tunnelSslBumping)
         storeAppendPrintf(e, " ssl-bump");
+#endif
 
-    if (s->cert)
-        storeAppendPrintf(e, " cert=%s", s->cert);
+    if (!s->secure.certFile.isEmpty())
+        storeAppendPrintf(e, " tls-cert=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.certFile));
 
-    if (s->key)
-        storeAppendPrintf(e, " key=%s", s->key);
+    if (!s->secure.privateKeyFile.isEmpty() && s->secure.privateKeyFile != s->secure.certFile)
+        storeAppendPrintf(e, " tls-key=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.privateKeyFile));
 
-    if (s->version)
-        storeAppendPrintf(e, " version=%d", s->version);
+    if (s->secure.sslVersion)
+        storeAppendPrintf(e, " tls-version=%d", s->secure.sslVersion);
 
-    if (s->options)
-        storeAppendPrintf(e, " options=%s", s->options);
+    if (!s->secure.sslOptions.isEmpty())
+        storeAppendPrintf(e, " tls-options=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.sslOptions));
 
-    if (s->cipher)
-        storeAppendPrintf(e, " cipher=%s", s->cipher);
+    if (!s->secure.sslCipher.isEmpty())
+        storeAppendPrintf(e, " tls-cipher=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.sslCipher));
 
-    if (s->cafile)
-        storeAppendPrintf(e, " cafile=%s", s->cafile);
+    if (!s->secure.caFile.isEmpty())
+        storeAppendPrintf(e, " tls-cafile=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.caFile));
 
-    if (s->capath)
-        storeAppendPrintf(e, " capath=%s", s->capath);
+    if (!s->secure.caDir.isEmpty())
+        storeAppendPrintf(e, " tls-capath=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.caDir));
 
-    if (s->crlfile)
-        storeAppendPrintf(e, " crlfile=%s", s->crlfile);
+    if (!s->secure.crlFile.isEmpty())
+        storeAppendPrintf(e, " tls-crlfile=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.crlFile));
 
+#if USE_OPENSSL
     if (s->dhfile)
         storeAppendPrintf(e, " dhparams=%s", s->dhfile);
 
-    if (!s->sslflags.isEmpty())
-        storeAppendPrintf(e, " sslflags=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->sslflags));
-
     if (s->sslContextSessionId)
         storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);
 
