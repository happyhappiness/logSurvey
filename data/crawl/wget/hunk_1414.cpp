             }
 
           if (!opt.server_response)
-            logprintf (LOG_VERBOSE, "==> CWD %s ... ", escnonprint (target));
+            logprintf (LOG_VERBOSE, "==> CWD %s ... ", 
+                       quotearg_style (escape_quoting_style, target));
           err = ftp_cwd (csock, target);
           /* FTPRERR, WRITEFAILED, FTPNSFOD */
           switch (err)
