       else
         con->csock = -1;
 
+#ifdef HAVE_SSL
+      if (u->scheme == SCHEME_FTPS)
+        {
+          /* If we're in implicit FTPS mode, we have to set up SSL/TLS before everything else.
+           * Otherwise we first read the server's greeting, and then send an "AUTH TLS".
+           */
+          if (opt.ftps_implicit)
+            {
+              err = init_control_ssl_connection (csock, u, &using_control_security);
+              if (err != NOCONERROR)
+                return err;
+              err = get_ftp_greeting (csock, con);
+              if (err != FTPOK)
+                return err;
+            }
+          else
+            {
+              err = get_ftp_greeting (csock, con);
+              if (err != FTPOK)
+                return err;
+              err = init_control_ssl_connection (csock, u, &using_control_security);
+              if (err != NOCONERROR)
+                return err;
+            }
+        }
+      else
+        {
+          err = get_ftp_greeting (csock, con);
+          if (err != FTPOK)
+            return err;
+        }
+#else
+      err = get_ftp_greeting (csock, con);
+      if (err != FTPOK)
+        return err;
+#endif
+
       /* Second: Login with proper USER/PASS sequence.  */
       logprintf (LOG_VERBOSE, _("Logging in as %s ... "),
                  quotearg_style (escape_quoting_style, user));
