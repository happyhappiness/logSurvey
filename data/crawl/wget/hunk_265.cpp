       return false;
     }
 
-  err = gnutls_handshake (session);
+  /* We don't stop the handshake process for non-fatal errors */
+  do
+    {
+      err = gnutls_handshake (session);
+      if (err < 0)
+        {
+          logprintf (LOG_NOTQUIET, "GnuTLS: %s\n", gnutls_strerror (err));
+          if (err == GNUTLS_E_WARNING_ALERT_RECEIVED ||
+              err == GNUTLS_E_FATAL_ALERT_RECEIVED)
+            {
+              alert = gnutls_alert_get (session);
+              str = gnutls_alert_get_name (alert);
+              if (str == NULL)
+                str = "(unknown)";
+              logprintf (LOG_NOTQUIET, "GnuTLS: received alert [%d]: %s\n", alert, str);
+            }
+        }
+    }
+  while (err == GNUTLS_E_WARNING_ALERT_RECEIVED && gnutls_error_is_fatal (err) == 0);
+
   if (err < 0)
     {
-      logprintf (LOG_NOTQUIET, "GnuTLS: %s\n", gnutls_strerror (err));
       gnutls_deinit (session);
       return false;
     }
