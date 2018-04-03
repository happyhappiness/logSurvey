       char *issuer = X509_NAME_oneline (X509_get_issuer_name (cert), 0, 0);
       logprintf (LOG_NOTQUIET,
                  _("%s: cannot verify %s's certificate, issued by %s:\n"),
-                 severity, quotearg_style (escape_quoting_style, host), 
+                 severity, quotearg_style (escape_quoting_style, host),
                  quote (issuer));
       /* Try to print more user-friendly (and translated) messages for
          the frequent verification errors.  */
