   return dir;
 }
 
-/* This function is just a stub.  It should actually accept some kind
-   of information what system it is running on -- e.g. FPL_UNIX,
-   FPL_DOS, FPL_NT, FPL_VMS, etc. and a "guess-me" value, like
-   FPL_GUESS.  Then it would call the appropriate parsers to fill up
-   fileinfos.
+#ifdef HAVE_FTPPARSE
+
+/* This is a "glue function" that connects the ftpparse interface to
+   the interface Wget expects.  ftpparse is used to parse listings
+   from servers other than Unix, like those running VMS or NT. */
+
+static struct fileinfo *
+ftp_parse_nonunix_ls (const char *file)
+{
+  FILE *fp;
+  int len;
+
+  char *line;          /* tokenizer */
+  struct fileinfo *dir, *l, cur; /* list creation */
+
+  fp = fopen (file, "rb");
+  if (!fp)
+    {
+      logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
+      return NULL;
+    }
+  dir = l = NULL;
+
+  /* Line loop to end of file: */
+  while ((line = read_whole_line (fp)))
+    {
+      struct ftpparse fp;
+
+      DEBUGP (("%s\n", line));
+      len = strlen (line);
+      /* Destroy <CR><LF> if present.  */
+      if (len && line[len - 1] == '\n')
+	line[--len] = '\0';
+      if (len && line[len - 1] == '\r')
+	line[--len] = '\0';
+
+      if (ftpparse(&fp, line, len))
+        {
+	  cur.size = fp.size;
+	  cur.name = (char *)xmalloc (fp.namelen + 1);
+	  memcpy (cur.name, fp.name, fp.namelen);
+	  cur.name[fp.namelen] = '\0';
+	  DEBUGP (("%s\n", cur.name));
+	  /* No links on non-UNIX systems */
+	  cur.linkto = NULL;
+	  /* ftpparse won't tell us correct permisions. So lets just invent
+	     something. */
+	  if (fp.flagtrycwd)
+	    {
+	      cur.type = FT_DIRECTORY;
+	      cur.perms = 0755;
+            } 
+	  else 
+	    {
+	      cur.type = FT_PLAINFILE;
+	      cur.perms = 0644;
+	    }
+	  if (!dir)
+	    {
+	      l = dir = (struct fileinfo *)xmalloc (sizeof (struct fileinfo));
+	      memcpy (l, &cur, sizeof (cur));
+	      l->prev = l->next = NULL;
+	    }
+	  else 
+	    {
+	      cur.prev = l;
+	      l->next = (struct fileinfo *)xmalloc (sizeof (struct fileinfo));
+	      l = l->next;
+	      memcpy (l, &cur, sizeof (cur));
+	      l->next = NULL;
+	    }
+	  l->tstamp = fp.mtime;
+      }
+
+      free (line);
+    }
+
+  fclose (fp);
+  return dir;
+}
+#endif
+
+/* This function switches between the correct parsing routine
+   depending on the SYSTEM_TYPE.  If system type is ST_UNIX, we use
+   our home-grown ftp_parse_unix_ls; otherwise, we use our interface
+   to ftpparse, also known as ftp_parse_nonunix_ls.  The system type
+   should be based on the result of the "SYST" response of the FTP
+   server.  */
 
-   Since we currently support only the Unix FTP servers, this function
-   simply returns the result of ftp_parse_unix_ls().  */
 struct fileinfo *
-ftp_parse_ls (const char *file)
+ftp_parse_ls (const char *file, const enum stype system_type)
 {
-  return ftp_parse_unix_ls (file);
+  if (system_type == ST_UNIX)
+    {
+      return ftp_parse_unix_ls (file);
+    }
+  else
+    {
+#ifdef HAVE_FTPPARSE
+      return ftp_parse_nonunix_ls (file);
+#else
+      /* #### Maybe log some warning here? */ 
+      return ftp_parse_unix_ls (file);
+#endif
+    }
 }
 
 /* Stuff for creating FTP index. */
