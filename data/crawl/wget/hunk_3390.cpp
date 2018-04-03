   return ocerr;
 }
 
+/* Creates a SSL Context and sets some defaults for it */
+uerr_t
+init_ssl (SSL_CTX **ctx)
+{
+  SSL_METHOD *meth = NULL;
+  int verify;
+  int can_validate;
+  SSL_library_init ();
+  SSL_load_error_strings ();
+  SSLeay_add_all_algorithms ();
+  SSLeay_add_ssl_algorithms ();
+  switch (opt.sslprotocol)
+    {
+      default:
+	meth = SSLv23_client_method ();
+	break;
+      case 1 :
+	meth = SSLv2_client_method ();
+	break;
+      case 2 :
+	meth = SSLv3_client_method ();
+	break;
+      case 3 :
+	meth = TLSv1_client_method ();
+	break;
+    }
+  if (meth == NULL)
+    {
+      ssl_printerrors ();
+      return SSLERRCTXCREATE;
+    }
+
+  *ctx = SSL_CTX_new (meth);
+  if (meth == NULL)
+    {
+      ssl_printerrors ();
+      return SSLERRCTXCREATE;
+    }
+  /* Can we validate the server Cert ? */
+  if (opt.sslcadir != NULL || opt.sslcafile != NULL)
+    {
+      SSL_CTX_load_verify_locations (*ctx, opt.sslcafile, opt.sslcadir);
+      can_validate = 1;
+    }
+  else
+    {
+      can_validate = 0;
+    }
+
+  if (!opt.sslcheckcert)
+    {
+      /* check cert but ignore error, do not break handshake on error */
+      verify = SSL_VERIFY_NONE;
+    }
+  else
+    {
+      if (!can_validate)
+	{
+	  logprintf (LOG_NOTQUIET, "Warrining validation of Server Cert not possible!\n");
+	  verify = SSL_VERIFY_NONE;
+	}
+     else
+	{
+	  /* break handshake if server cert is not valid but allow NO-Cert mode */
+	  verify = SSL_VERIFY_PEER;
+	}
+    }
+
+  SSL_CTX_set_verify (*ctx, verify, verify_callback);
+
+  if (opt.sslcertfile != NULL || opt.sslcertkey != NULL)
+    {
+      int ssl_cert_type;
+      if (!opt.sslcerttype)
+	ssl_cert_type = SSL_FILETYPE_PEM;
+      else
+	ssl_cert_type = SSL_FILETYPE_ASN1;
+
+      if (opt.sslcertkey == NULL) 
+	opt.sslcertkey = opt.sslcertfile;
+      if (opt.sslcertfile == NULL)
+	opt.sslcertfile = opt.sslcertkey; 
+
+      if (SSL_CTX_use_certificate_file (*ctx, opt.sslcertfile, ssl_cert_type) <= 0)
+	{
+	  ssl_printerrors ();
+  	  return SSLERRCERTFILE;
+	}
+      if (SSL_CTX_use_PrivateKey_file  (*ctx, opt.sslcertkey , ssl_cert_type) <= 0)
+	{
+	  ssl_printerrors ();
+	  return SSLERRCERTKEY;
+	}
+    }
+
+  return 0; /* Succeded */
+}
+
+void
+shutdown_ssl (SSL* con)
+{
+  if (con == NULL)
+    return;
+  if (0==SSL_shutdown (con))
+    SSL_shutdown (con);
+  SSL_free (con);
+}
+
+/* Sets up a SSL structure and performs the handshake on fd 
+   Returns 0 if everything went right
+   Returns 1 if something went wrong ----- TODO: More exit codes
+*/
+int
+connect_ssl (SSL **con, SSL_CTX *ctx, int fd) 
+{
+  if (NULL == (*con = SSL_new (ctx)))
+    {
+      ssl_printerrors ();
+      return 1;
+    }
+  if (!SSL_set_fd (*con, fd))
+    {
+      ssl_printerrors ();
+      return 1;
+    }
+  SSL_set_connect_state (*con);
+  switch (SSL_connect (*con))
+    {
+      case 1 : 
+	return (*con)->state != SSL_ST_OK;
+      default:
+        ssl_printerrors ();
+	shutdown_ssl (*con);
+	*con = NULL;
+	return 1;
+      case 0 :
+        ssl_printerrors ();
+	SSL_free (*con);
+       	*con = NULL;
+ 	return 1;
+    }
+  return 0;
+}
+
+void
+free_ssl_ctx (SSL_CTX * ctx)
+{
+  SSL_CTX_free (ctx);
+}
+
 /* SSL version of iread.  Only exchanged read for SSL_read Read at
    most LEN bytes from FD, storing them to BUF. */
 
