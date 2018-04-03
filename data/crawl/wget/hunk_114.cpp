 
 static uerr_t ftp_get_listing (struct url *, ccon *, struct fileinfo **);
 
+static uerr_t
+get_ftp_greeting(int csock, ccon *con)
+{
+  uerr_t err = 0;
+
+  /* Get the server's greeting */
+  err = ftp_greeting (csock);
+  if (err != FTPOK)
+    {
+      logputs (LOG_NOTQUIET, "Error in server response. Closing.\n");
+      fd_close (csock);
+      con->csock = -1;
+    }
+
+  return err;
+}
+
+#ifdef HAVE_SSL
+static uerr_t
+init_control_ssl_connection (int csock, struct url *u, bool *using_control_security)
+{
+  bool using_security = false;
+
+  /* If '--ftps-implicit' was passed, perform the SSL handshake directly,
+   * and do not send an AUTH command.
+   * Otherwise send an AUTH sequence before login,
+   * and perform the SSL handshake if accepted by server.
+   */
+  if (!opt.ftps_implicit && !opt.server_response)
+    logputs (LOG_VERBOSE, "==> AUTH TLS ... ");
+  if (opt.ftps_implicit || ftp_auth (csock, SCHEME_FTPS) == FTPOK)
+    {
+      if (!ssl_connect_wget (csock, u->host, NULL))
+        {
+          fd_close (csock);
+          return CONSSLERR;
+        }
+      else if (!ssl_check_certificate (csock, u->host))
+        {
+          fd_close (csock);
+          return VERIFCERTERR;
+        }
+
+      if (!opt.ftps_implicit && !opt.server_response)
+        logputs (LOG_VERBOSE, " done.\n");
+
+      /* If implicit FTPS was requested, we act as "normal" FTP, but over SSL.
+       * We're not using RFC 2228 commands.
+       */
+      using_security = true;
+    }
+  else
+    {
+      /* The server does not support 'AUTH TLS'.
+       * Check if --ftps-fallback-to-ftp was passed. */
+      if (opt.ftps_fallback_to_ftp)
+        {
+          logputs (LOG_NOTQUIET, "Server does not support AUTH TLS. Falling back to FTP.\n");
+          using_security = false;
+        }
+      else
+        {
+          fd_close (csock);
+          return FTPNOAUTH;
+        }
+    }
+
+  *using_control_security = using_security;
+  return NOCONERROR;
+}
+#endif
+
 /* Retrieves a file with denoted parameters through opening an FTP
    connection to the server.  It always closes the data connection,
    and closes the control connection in case of error.  If warc_tmp
