    line is 0-terminated.  All the response lines but the last one are
    skipped.  The last line is determined as described in RFC959.  */
 uerr_t
-ftp_response (struct rbuf *rbuf, char **line)
+ftp_response (int fd, char **ret_line)
 {
-  int i;
-  int bufsize = 40;
-
-  *line = (char *)xmalloc (bufsize);
-  do
+  while (1)
     {
-      for (i = 0; 1; i++)
-        {
-          int res;
-          if (i > bufsize - 1)
-            *line = (char *)xrealloc (*line, (bufsize <<= 1));
-          res = RBUF_READCHAR (rbuf, *line + i);
-          /* RES is number of bytes read.  */
-          if (res == 1)
-            {
-              if ((*line)[i] == '\n')
-                {
-                  (*line)[i] = '\0';
-                  /* Get rid of \r.  */
-                  if (i > 0 && (*line)[i - 1] == '\r')
-                    (*line)[i - 1] = '\0';
-                  break;
-                }
-            }
-          else
-            return FTPRERR;
-        }
+      char *line = fd_read_line (fd);
+      if (!line)
+	return FTPRERR;
       if (opt.server_response)
-        logprintf (LOG_ALWAYS, "%s\n", *line);
+        logputs (LOG_NOTQUIET, line);
       else
-        DEBUGP (("%s\n", *line));
+        DEBUGP (("%s", line));
+      if (ISDIGIT (line[0]) && ISDIGIT (line[1]) && ISDIGIT (line[2])
+	  && line[3] == ' ')
+	{
+	  char *p = line + strlen (line);
+	  if (p > line && p[-1] == '\n')
+	    *--p = '\0';
+	  if (p > line && p[-1] == '\r')
+	    *--p = '\0';
+	  strncpy (ftp_last_respline, line, sizeof (ftp_last_respline));
+	  ftp_last_respline[sizeof (ftp_last_respline) - 1] = '\0';
+	  *ret_line = line;
+	  return FTPOK;
+	}
+      xfree (line);
     }
-  while (!(i >= 3 && ISDIGIT (**line) && ISDIGIT ((*line)[1]) &&
-           ISDIGIT ((*line)[2]) && (*line)[3] == ' '));
-  strncpy (ftp_last_respline, *line, sizeof (ftp_last_respline));
-  ftp_last_respline[sizeof (ftp_last_respline) - 1] = '\0';
-  return FTPOK;
 }
 
 /* Returns the malloc-ed FTP request, ending with <CR><LF>, printing
