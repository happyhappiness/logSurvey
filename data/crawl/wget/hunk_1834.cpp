   if (!cert)
     {
       logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
-                 severity, escnonprint (host));
+                 severity, quotearg_style (escape_quoting_style, host));
       success = false;
       goto no_cert;             /* must bail out since CERT is NULL */
     }
