       ssl_print_errors ();
       return SSLERRCTXCREATE;
     }
-  /* Can we validate the server Cert ? */
-  if (opt.sslcadir != NULL || opt.sslcafile != NULL)
-    {
-      SSL_CTX_load_verify_locations (ssl_ctx, opt.sslcafile, opt.sslcadir);
-      can_validate = 1;
-    }
-  else
-    {
-      can_validate = 0;
-    }
 
-  if (!opt.sslcheckcert)
-    {
-      /* check cert but ignore error, do not break handshake on error */
-      verify = SSL_VERIFY_NONE;
-    }
-  else
+  SSL_CTX_set_default_verify_paths (ssl_ctx);
+  SSL_CTX_load_verify_locations (ssl_ctx, opt.ca_cert, opt.ca_directory);
+  SSL_CTX_set_verify (ssl_ctx,
+		      opt.check_cert ? SSL_VERIFY_PEER : SSL_VERIFY_NONE,
+		      verify_callback);
+
+  if (opt.cert_file != NULL || opt.cert_key != NULL)
     {
-      if (!can_validate)
-	{
-	  logputs (LOG_NOTQUIET,
-		   _("Warning: validation of server certificate not possible!\n"));
-	  verify = SSL_VERIFY_NONE;
-	}
-     else
+      int ssl_cert_type;
+      switch (opt.cert_type)
 	{
-	  /* break handshake if server cert is not valid but allow
-	     NO-Cert mode */
-	  verify = SSL_VERIFY_PEER;
+	case cert_type_pem:
+	  ssl_cert_type = SSL_FILETYPE_PEM;
+	  break;
+	case cert_type_asn1:
+	  ssl_cert_type = SSL_FILETYPE_ASN1;
+	  break;
 	}
-    }
 
-  SSL_CTX_set_verify (ssl_ctx, verify, verify_callback);
+#if 0 /* what was this supposed to achieve? */
+      if (opt.cert_key == NULL) 
+	opt.cert_key = opt.cert_file;
+      if (opt.cert_file == NULL)
+	opt.cert_file = opt.cert_key;
+#endif
 
-  if (opt.sslcertfile != NULL || opt.sslcertkey != NULL)
-    {
-      int ssl_cert_type;
-      if (!opt.sslcerttype)
-	ssl_cert_type = SSL_FILETYPE_PEM;
-      else
-	ssl_cert_type = SSL_FILETYPE_ASN1;
-
-      if (opt.sslcertkey == NULL) 
-	opt.sslcertkey = opt.sslcertfile;
-      if (opt.sslcertfile == NULL)
-	opt.sslcertfile = opt.sslcertkey; 
-
-      if (SSL_CTX_use_certificate_file (ssl_ctx, opt.sslcertfile,
-					ssl_cert_type) <= 0)
+      if (SSL_CTX_use_certificate_file (ssl_ctx, opt.cert_file,
+					ssl_cert_type) != 1)
 	{
 	  ssl_print_errors ();
   	  return SSLERRCERTFILE;
 	}
-      if (SSL_CTX_use_PrivateKey_file  (ssl_ctx, opt.sslcertkey,
-					ssl_cert_type) <= 0)
+      if (SSL_CTX_use_PrivateKey_file (ssl_ctx, opt.cert_key,
+				       ssl_cert_type) != 1)
 	{
 	  ssl_print_errors ();
 	  return SSLERRCERTKEY;
