             if (!SSL_CTX_use_certificate_chain_file(ctx.get(), certfile)) {
                 const int ssl_error = ERR_get_error();
                 fatalf("Failed to acquire SSL certificate '%s': %s\n",
-                       certfile, ERR_error_string(ssl_error, NULL));
+                       certfile, Security::ErrorString(ssl_error));
             }
 
             debugs(83, DBG_IMPORTANT, "Using private key in " << keys.privateKeyFile);
