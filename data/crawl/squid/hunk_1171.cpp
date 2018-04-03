         fatalf("Your OpenSSL has no SSL engine support\n");
 #endif
 
+    const char *defName = Config.SSL.certSignHash ? Config.SSL.certSignHash : SQUID_SSL_SIGN_HASH_IF_NONE;
+    Ssl::DefaultSignHash = EVP_get_digestbyname(defName);
+    if (!Ssl::DefaultSignHash)
+        fatalf("Sign hash '%s' is not supported\n", defName);
+
     ssl_ex_index_server = SSL_get_ex_new_index(0, (void *) "server", NULL, NULL, NULL);
     ssl_ctx_ex_index_dont_verify_domain = SSL_CTX_get_ex_new_index(0, (void *) "dont_verify_domain", NULL, NULL, NULL);
     ssl_ex_index_cert_error_check = SSL_get_ex_new_index(0, (void *) "cert_error_check", NULL, &ssl_dupAclChecklist, &ssl_freeAclChecklist);
