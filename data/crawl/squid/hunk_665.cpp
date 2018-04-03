         ssl_ask_password(sslContext, keyfile);
 
         if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
-            ssl_error = ERR_get_error();
+            const int ssl_error = ERR_get_error();
             fatalf("Failed to acquire SSL private key '%s': %s\n",
                    keyfile, ERR_error_string(ssl_error, NULL));
         }
 
         debugs(83, 5, "Comparing private and public SSL keys.");
 
         if (!SSL_CTX_check_private_key(sslContext)) {
-            ssl_error = ERR_get_error();
+            const int ssl_error = ERR_get_error();
             fatalf("SSL private key '%s' does not match public key '%s': %s\n",
                    certfile, keyfile, ERR_error_string(ssl_error, NULL));
         }
