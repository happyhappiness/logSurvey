     return op;
 }
 
-SSL_CTX *
-sslCreateContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options)
+#define SSL_FLAG_NO_DEFAULT_CA		(1<<0)
+#define SSL_FLAG_DELAYED_AUTH		(1<<1)
+#define SSL_FLAG_DONT_VERIFY_PEER	(1<<2)
+#define SSL_FLAG_DONT_VERIFY_DOMAIN	(1<<3)
+
+static long
+ssl_parse_flags(const char *flags)
+{
+    long fl = 0;
+    char *tmp;
+    char *flag;
+
+    if (!flags)
+	return 0;
+
+    tmp = xstrdup(flags);
+    flag = strtok(tmp, ":,");
+    while (flag) {
+	if (strcmp(flag, "NO_DEFAULT_CA") == 0)
+	    fl |= SSL_FLAG_NO_DEFAULT_CA;
+	else if (strcmp(flag, "DELAYED_AUTH") == 0)
+	    fl |= SSL_FLAG_DELAYED_AUTH;
+	else if (strcmp(flag, "DONT_VERIFY_PEER") == 0)
+	    fl |= SSL_FLAG_DONT_VERIFY_PEER;
+	else if (strcmp(flag, "DONT_VERIFY_DOMAIN") == 0)
+	    fl |= SSL_FLAG_DONT_VERIFY_DOMAIN;
+	else
+	    fatalf("Unknown ssl flag '%s'", flag);
+	flag = strtok(NULL, ":,");
+    }
+    safe_free(tmp);
+    return fl;
+}
+
+
+static void
+ssl_initialize(void)
 {
-    int ssl_error;
-    SSL_METHOD *method;
-    SSL_CTX *sslContext;
     static int ssl_initialized = 0;
     if (!ssl_initialized) {
 	ssl_initialized = 1;
 	SSL_load_error_strings();
 	SSLeay_add_ssl_algorithms();
+#ifdef HAVE_OPENSSL_ENGINE_H
+	if (Config.SSL.ssl_engine) {
+	    ENGINE *e;
+	    if (!(e = ENGINE_by_id(Config.SSL.ssl_engine))) {
+		fatalf("Unable to find SSL engine '%s'\n", Config.SSL.ssl_engine);
+	    }
+	    if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
+		int ssl_error = ERR_get_error();
+		fatalf("Failed to initialise SSL engine: %s\n",
+		    ERR_error_string(ssl_error, NULL));
+	    }
+	}
+#else
+	if (Config.SSL.ssl_engine) {
+	    fatalf("Your OpenSSL has no SSL engine support\n");
+	}
+#endif
     }
+    ssl_ex_index_server = SSL_get_ex_new_index(0, (void *) "server", NULL, NULL, NULL);
+    ssl_ctx_ex_index_dont_verify_domain = SSL_CTX_get_ex_new_index(0, (void *) "dont_verify_domain", NULL, NULL, NULL);
+
+}
+
+SSL_CTX *
+sslCreateServerContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options, const char *flags, const char *clientCA, const char *CAfile, const char *CApath)
+{
+    int ssl_error;
+    SSL_METHOD *method;
+    SSL_CTX *sslContext;
+    long fl = ssl_parse_flags(flags);
+
+    ssl_initialize();
+
     if (!keyfile)
 	keyfile = certfile;
     if (!certfile)
 	certfile = keyfile;
+    if (!CAfile)
+	CAfile = clientCA;
 
     debug(83, 1) ("Initialising SSL.\n");
     switch (version) {
