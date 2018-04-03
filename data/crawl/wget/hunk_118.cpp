   else if (expected_bytes)
     print_length (expected_bytes, restval, false);
 
+#ifdef HAVE_SSL
+  if (u->scheme == SCHEME_FTPS && using_data_security)
+    {
+      /* We should try to restore the existing SSL session in the data connection
+       * and fall back to establishing a new session if the server doesn't want to restore it.
+       */
+      if (!opt.ftps_resume_ssl || !ssl_connect_wget (dtsock, u->host, &csock))
+        {
+          if (opt.ftps_resume_ssl)
+            logputs (LOG_NOTQUIET, "Server does not want to resume the SSL session. Trying with a new one.\n");
+          if (!ssl_connect_wget (dtsock, u->host, NULL))
+            {
+              fd_close (csock);
+              fd_close (dtsock);
+              logputs (LOG_NOTQUIET, "Could not perform SSL handshake.\n");
+              return CONERROR;
+            }
+        }
+      else
+        logputs (LOG_NOTQUIET, "Resuming SSL session in data connection.\n");
+
+      if (!ssl_check_certificate (dtsock, u->host))
+        {
+          fd_close (csock);
+          fd_close (dtsock);
+          return CONERROR;
+        }
+    }
+#endif
+
   /* Get the contents of the document.  */
   flags = 0;
   if (restval && rest_failed)
