               logputs (LOG_VERBOSE, number_to_static_string (contlen + contrange));
               if (contlen + contrange >= 1024)
                 logprintf (LOG_VERBOSE, " (%s)",
-                           human_readable (contlen + contrange));
+                           human_readable (contlen + contrange, 10, 1));
               if (contrange)
                 {
                   if (contlen >= 1024)
                     logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
                                number_to_static_string (contlen),
-                               human_readable (contlen));
+                               human_readable (contlen, 10, 1));
                   else
                     logprintf (LOG_VERBOSE, _(", %s remaining"),
                                number_to_static_string (contlen));
