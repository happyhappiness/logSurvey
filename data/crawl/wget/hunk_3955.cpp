 {
   return ftp_parse_unix_ls (file);
 }
+
+/* Stuff for creating FTP index. */
+
+/* The function returns the pointer to the malloc-ed quoted version of
+   string s.  It will recognize and quote numeric and special graphic
+   entities, as per RFC1866:
+
+   `&' -> `&amp;'
+   `<' -> `&lt;'
+   `>' -> `&gt;'
+   `"' -> `&quot;'
+
+   No other entities are recognized or replaced.  */
+static char *
+html_quote_string (const char *s)
+{
+  const char *b = s;
+  char *p, *res;
+  int i;
+
+  /* Pass through the string, and count the new size.  */
+  for (i = 0; *s; s++, i++)
+    {
+      if (*s == '&')
+	i += 4;                /* `amp;' */
+      else if (*s == '<' || *s == '>')
+	i += 3;                /* `lt;' and `gt;' */
+      else if (*s == '\"')
+	i += 5;                /* `quot;' */
+    }
+  res = (char *)xmalloc (i + 1);
+  s = b;
+  for (p = res; *s; s++)
+    {
+      switch (*s)
+	{
+	case '&':
+	  *p++ = '&';
+	  *p++ = 'a';
+	  *p++ = 'm';
+	  *p++ = 'p';
+	  *p++ = ';';
+	  break;
+	case '<': case '>':
+	  *p++ = '&';
+	  *p++ = (*s == '<' ? 'l' : 'g');
+	  *p++ = 't';
+	  *p++ = ';';
+	  break;
+	case '\"':
+	  *p++ = '&';
+	  *p++ = 'q';
+	  *p++ = 'u';
+	  *p++ = 'o';
+	  *p++ = 't';
+	  *p++ = ';';
+	  break;
+	default:
+	  *p++ = *s;
+	}
+    }
+  *p = '\0';
+  return res;
+}
+
+/* The function creates an HTML index containing references to given
+   directories and files on the appropriate host.  The references are
+   FTP.  */
+uerr_t
+ftp_index (const char *file, struct urlinfo *u, struct fileinfo *f)
+{
+  FILE *fp;
+  char *upwd;
+  char *htclfile;		/* HTML-clean file name */
+
+  if (!opt.dfp)
+    {
+      fp = fopen (file, "wb");
+      if (!fp)
+	{
+	  logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
+	  return FOPENERR;
+	}
+    }
+  else
+    fp = opt.dfp;
+  if (u->user)
+    {
+      char *tmpu, *tmpp;        /* temporary, clean user and passwd */
+
+      tmpu = CLEANDUP (u->user);
+      tmpp = u->passwd ? CLEANDUP (u->passwd) : NULL;
+      upwd = (char *)xmalloc (strlen (tmpu)
+			     + (tmpp ? (1 + strlen (tmpp)) : 0) + 2);
+      sprintf (upwd, "%s%s%s@", tmpu, tmpp ? ":" : "", tmpp ? tmpp : "");
+      free (tmpu);
+      FREE_MAYBE (tmpp);
+    }
+  else
+    upwd = xstrdup ("");
+  fprintf (fp, "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">\n");
+  fprintf (fp, "<html>\n<head>\n<title>");
+  fprintf (fp, _("Index of /%s on %s:%d"), u->dir, u->host, u->port);
+  fprintf (fp, "</title>\n</head>\n<body>\n<h1>");
+  fprintf (fp, _("Index of /%s on %s:%d"), u->dir, u->host, u->port);
+  fprintf (fp, "</h1>\n<hr>\n<pre>\n");
+  while (f)
+    {
+      fprintf (fp, "  ");
+      if (f->tstamp != -1)
+	{
+	  /* #### Should we translate the months? */
+	  static char *months[] = {
+	    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
+	    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
+	  };
+	  struct tm *ptm = localtime ((time_t *)&f->tstamp);
+
+	  fprintf (fp, "%d %s %02d ", ptm->tm_year + 1900, months[ptm->tm_mon],
+		  ptm->tm_mday);
+	  if (ptm->tm_hour)
+	    fprintf (fp, "%02d:%02d  ", ptm->tm_hour, ptm->tm_min);
+	  else
+	    fprintf (fp, "       ");
+	}
+      else
+	fprintf (fp, _("time unknown       "));
+      switch (f->type)
+	{
+	case FT_PLAINFILE:
+	  fprintf (fp, _("File        "));
+	  break;
+	case FT_DIRECTORY:
+	  fprintf (fp, _("Directory   "));
+	  break;
+	case FT_SYMLINK:
+	  fprintf (fp, _("Link        "));
+	  break;
+	default:
+	  fprintf (fp, _("Not sure    "));
+	  break;
+	}
+      htclfile = html_quote_string (f->name);
+      fprintf (fp, "<a href=\"ftp://%s%s:%hu", upwd, u->host, u->port);
+      if (*u->dir != '/')
+	putc ('/', fp);
+      fprintf (fp, "%s", u->dir);
+      if (*u->dir)
+	putc ('/', fp);
+      fprintf (fp, "%s", htclfile);
+      if (f->type == FT_DIRECTORY)
+	putc ('/', fp);
+      fprintf (fp, "\">%s", htclfile);
+      if (f->type == FT_DIRECTORY)
+	putc ('/', fp);
+      fprintf (fp, "</a> ");
+      if (f->type == FT_PLAINFILE)
+	fprintf (fp, _(" (%s bytes)"), legible (f->size));
+      else if (f->type == FT_SYMLINK)
+	fprintf (fp, "-> %s", f->linkto ? f->linkto : "(nil)");
+      putc ('\n', fp);
+      free (htclfile);
+      f = f->next;
+    }
+  fprintf (fp, "</pre>\n</body>\n</html>\n");
+  free (upwd);
+  if (!opt.dfp)
+    fclose (fp);
+  else
+    fflush (fp);
+  return FTPOK;
+}
