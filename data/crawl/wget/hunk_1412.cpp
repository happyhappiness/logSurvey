         *--p = '\0';
 
       if (opt.server_response)
-        logprintf (LOG_NOTQUIET, "%s\n", escnonprint (line));
+        logprintf (LOG_NOTQUIET, "%s\n", 
+                   quotearg_style (escape_quoting_style, line));
       else
-        DEBUGP (("%s\n", escnonprint (line)));
+        DEBUGP (("%s\n", quotearg_style (escape_quoting_style, line)));
 
       /* The last line of output is the one that begins with "ddd ". */
       if (c_isdigit (line[0]) && c_isdigit (line[1]) && c_isdigit (line[2])
