   local_sock = -1;
   con->dltime = 0;
 
+#ifdef HAVE_SSL
+  if (u->scheme == SCHEME_FTPS)
+    {
+      /* Initialize SSL layer first */
+      if (!ssl_init ())
+        {
+          scheme_disable (SCHEME_FTPS);
+          logprintf (LOG_NOTQUIET, _("Could not initialize SSL. It will be disabled."));
+          err = SSLINITFAILED;
+          return err;
+        }
+
+      /* If we're using the default FTP port and implicit FTPS was requested,
+       * rewrite the port to the default *implicit* FTPS port.
+       */
+      if (opt.ftps_implicit && u->port == DEFAULT_FTP_PORT)
+        {
+          DEBUGP (("Implicit FTPS was specified. Rewriting default port to %d.\n", DEFAULT_FTPS_IMPLICIT_PORT));
+          u->port = DEFAULT_FTPS_IMPLICIT_PORT;
+        }
+    }
+#endif
+
   if (!(cmd & DO_LOGIN))
-    csock = con->csock;
+    {
+      csock = con->csock;
+      using_data_security = con->st & DATA_CHANNEL_SECURITY;
+    }
   else                          /* cmd & DO_LOGIN */
     {
       char    *host = con->proxy ? con->proxy->host : u->host;
