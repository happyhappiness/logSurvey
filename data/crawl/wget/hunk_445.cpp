         *--p = '\0';
 
       if (opt.server_response)
-        logprintf (LOG_NOTQUIET, "%s\n", 
+        logprintf (LOG_NOTQUIET, "%s\n",
                    quotearg_style (escape_quoting_style, line));
       else
         DEBUGP (("%s\n", quotearg_style (escape_quoting_style, line)));
