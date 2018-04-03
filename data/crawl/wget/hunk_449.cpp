               char *p = strchr (line, '\0');
               while (p > line && (p[-1] == '\n' || p[-1] == '\r'))
                 *--p = '\0';
-              logprintf (LOG_ALWAYS, "%s\n", 
+              logprintf (LOG_ALWAYS, "%s\n",
                          quotearg_style (escape_quoting_style, line));
               xfree (line);
             }
