       if (opt.verbose)
         {
           if (!opt.server_response)
-            logprintf (LOG_VERBOSE, "==> SIZE %s ... ", escnonprint (u->file));
+            logprintf (LOG_VERBOSE, "==> SIZE %s ... ", 
+                       quotearg_style (escape_quoting_style, u->file));
         }
 
       err = ftp_size (csock, u->file, len);
