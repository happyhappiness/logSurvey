 	--line_end;
       if (line_end > line_beg)
 	{
-	  urlpos *entry = (urlpos *)xmalloc (sizeof (urlpos));
+	  int up_error_code;
+	  char *url_text;
+	  struct urlpos *entry;
+	  struct url *url;
+
+	  /* We must copy the URL to a zero-terminated string.  *sigh*.  */
+	  url_text = strdupdelim (line_beg, line_end);
+	  url = url_parse (url_text, &up_error_code);
+	  if (!url)
+	    {
+	      logprintf (LOG_NOTQUIET, "%s: Invalid URL %s: %s\n",
+			 file, url_text, url_error (up_error_code));
+	      xfree (url_text);
+	      continue;
+	    }
+	  xfree (url_text);
+
+	  entry = (struct urlpos *)xmalloc (sizeof (struct urlpos));
 	  memset (entry, 0, sizeof (*entry));
 	  entry->next = NULL;
-	  entry->url = strdupdelim (line_beg, line_end);
+	  entry->url = url;
+
 	  if (!head)
 	    head = entry;
 	  else
