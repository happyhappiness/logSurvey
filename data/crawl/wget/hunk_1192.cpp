             logputs (LOG_VERBOSE,
                      opt.ignore_length ? _("ignored") : _("unspecified"));
           if (type)
-            logprintf (LOG_VERBOSE, " [%s]\n", escnonprint (type));
+            logprintf (LOG_VERBOSE, " [%s]\n", quotearg_style (escape_quoting_style, type));
           else
             logputs (LOG_VERBOSE, "\n");
         }
