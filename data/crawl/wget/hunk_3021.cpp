 
 /* Print SSL errors. */
 
-void
+static void
 ssl_print_errors (void) 
 {
   unsigned long curerr = 0;
-  char errbuff[1024];
-  xzero (errbuff);
   while ((curerr = ERR_get_error ()) != 0)
-    logprintf (LOG_NOTQUIET, "OpenSSL: %s\n",
-	       ERR_error_string (curerr, errbuff));
+    logprintf (LOG_NOTQUIET, "OpenSSL: %s\n", ERR_error_string (curerr, NULL));
 }
 
 /* Creates a SSL Context and sets some defaults for it */