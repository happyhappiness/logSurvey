 static void
 print_errors (void) 
 {
-  unsigned long curerr = 0;
-  while ((curerr = ERR_get_error ()) != 0)
-    logprintf (LOG_NOTQUIET, "OpenSSL: %s\n", ERR_error_string (curerr, NULL));
+  unsigned long err;
+  while ((err = ERR_get_error ()) != 0)
+    logprintf (LOG_NOTQUIET, "OpenSSL: %s\n", ERR_error_string (err, NULL));
 }
 
 /* Convert keyfile type as used by options.h to a type as accepted by
