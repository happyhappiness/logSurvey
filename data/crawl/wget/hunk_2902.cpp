     }
 }
 
-/* Creates a SSL Context and sets some defaults for it */
-uerr_t
+/* Create an SSL Context and set default paths etc.  Called the first
+   time an HTTP download is attempted.
+
+   Returns 0 on success, non-zero otherwise.  */
+
+int
 ssl_init ()
 {
-  SSL_METHOD *meth = NULL;
+  SSL_METHOD *meth;
 
   if (ssl_ctx)
-    return 0;
+    /* The SSL has already been initialized. */
+    return 1;
 
   /* Init the PRNG.  If that fails, bail out.  */
-  ssl_init_prng ();
-  if (RAND_status () == 0)
+  init_prng ();
+  if (RAND_status () != 1)
     {
       logprintf (LOG_NOTQUIET,
-		 _("Could not seed OpenSSL PRNG; disabling SSL.\n"));
-      scheme_disable (SCHEME_HTTPS);
-      return SSLERRCTXCREATE;
+		 _("Could not seed PRNG; consider using --random-file.\n"));
+      goto error;
     }
 
   SSL_library_init ();
   SSL_load_error_strings ();
   SSLeay_add_all_algorithms ();
   SSLeay_add_ssl_algorithms ();
+
   switch (opt.secure_protocol)
     {
     case secure_protocol_auto:
