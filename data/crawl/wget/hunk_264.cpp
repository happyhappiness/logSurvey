         logprintf (LOG_ALWAYS, "%s: %s\n", con->target, strerror (errno));
       else
         {
-          char *line;
-          /* The lines are being read with read_whole_line because of
+          char *line = NULL;
+          size_t bufsize = 0;
+          ssize_t len;
+
+          /* The lines are being read with getline because of
              no-buffering on opt.lfile.  */
-          while ((line = read_whole_line (fp)) != NULL)
+          while ((len = getline (&line, &bufsize, fp)) > 0)
             {
-              char *p = strchr (line, '\0');
-              while (p > line && (p[-1] == '\n' || p[-1] == '\r'))
-                *--p = '\0';
+              while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
+                line[--len] = '\0';
               logprintf (LOG_ALWAYS, "%s\n",
                          quotearg_style (escape_quoting_style, line));
-              xfree (line);
             }
+          xfree (line);
           fclose (fp);
         }
     } /* con->cmd & DO_LIST && server_response */
