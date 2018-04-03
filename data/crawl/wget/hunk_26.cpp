             {
               gnutls_alert_description_t alert = gnutls_alert_get (session);
               const char *str = gnutls_alert_get_name (alert);
-              logprintf (LOG_NOTQUIET, "GnuTLS: received alert [%d]: %s\n",
+              logprintf (LOG_NOTQUIET, "GnuTLS: received alert [%u]: %s\n",
                          alert, str ? str : "(unknown)");
             }
         }
