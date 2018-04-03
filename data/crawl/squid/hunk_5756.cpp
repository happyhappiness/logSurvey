 	fatalf("Failed to allocate SSL context: %s\n",
 	    ERR_error_string(ssl_error, NULL));
     }
-    SSL_CTX_set_options(sslContext, SSL_OP_ALL);
+    SSL_CTX_set_options(sslContext, ssl_parse_options(options));
 
+    if (cipher) {
+	debug(81, 5) ("Using chiper suite %s.\n", cipher);
+	if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
+	    ssl_error = ERR_get_error();
+	    fatalf("Failed to set SSL cipher suite: %s\n",
+		ERR_error_string(ssl_error, NULL));
+	}
+    }
     debug(81, 1) ("Using certificate in %s\n", certfile);
     if (!SSL_CTX_use_certificate_file(sslContext, certfile, SSL_FILETYPE_PEM)) {
 	ssl_error = ERR_get_error();
