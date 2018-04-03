           xfree (name);
         }
 
-      logprintf (LOG_VERBOSE, _("Resolving %s... "), 
+      logprintf (LOG_VERBOSE, _("Resolving %s... "),
                  quotearg_style (escape_quoting_style, str ? str : host));
 
       if (str)
