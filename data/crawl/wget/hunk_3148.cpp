 	}
     }
 
-  /* Loop through the headers and process them. */
+  DEBUGP (("\n---response begin---\n"));
+  DEBUGP (("%s", head));
+  DEBUGP (("---response end---\n"));
 
-  hcount = 0;
-  for (hdr_beg = head;
-       (hdr_end = next_header (hdr_beg));
-       hdr_beg = hdr_end)
-    {
-      char *hdr = strdupdelim (hdr_beg, hdr_end);
-      {
-	char *tmp = hdr + strlen (hdr);
-	if (tmp > hdr && tmp[-1] == '\n')
-	  *--tmp = '\0';
-	if (tmp > hdr && tmp[-1] == '\r')
-	  *--tmp = '\0';
-      }
-      ++hcount;
+  resp = response_new (head);
 
-      /* Check for status line.  */
-      if (hcount == 1)
-	{
-	  const char *error;
-	  /* Parse the first line of server response.  */
-	  statcode = parse_http_status_line (hdr, &error);
-	  hs->statcode = statcode;
-	  /* Store the descriptive response.  */
-	  if (statcode == -1) /* malformed response */
-	    {
-	      /* A common reason for "malformed response" error is the
-                 case when no data was actually received.  Handle this
-                 special case.  */
-	      if (!*hdr)
-		hs->error = xstrdup (_("No data received"));
-	      else
-		hs->error = xstrdup (_("Malformed status line"));
-	      xfree (hdr);
-	      break;
-	    }
-	  else if (!*error)
-	    hs->error = xstrdup (_("(no description)"));
-	  else
-	    hs->error = xstrdup (error);
-
-	  if ((statcode != -1)
-#ifdef ENABLE_DEBUG
-	      && !opt.debug
-#endif
-	      )
-	    {
-             if (opt.server_response)
-	       logprintf (LOG_VERBOSE, "\n%2d %s", hcount, hdr);
-             else
-	       logprintf (LOG_VERBOSE, "%2d %s", statcode, error);
-	    }
+  /* Check for status line.  */
+  message = NULL;
+  statcode = response_status (resp, &message);
+  if (!opt.server_response)
+    logprintf (LOG_VERBOSE, "%2d %s\n", statcode, message ? message : "");
+  else
+    {
+      logprintf (LOG_VERBOSE, "\n");
+      print_server_response (resp);
+    }
 
-	  goto done_header;
-	}
+  hs->statcode = statcode;
+  if (statcode == -1)
+    hs->error = xstrdup (_("Malformed status line"));
+  else if (!*message)
+    hs->error = xstrdup (_("(no description)"));
+  else
+    hs->error = xstrdup (message);
 
-      /* Exit on empty header.  */
-      if (!*hdr)
+  if (response_header_copy (resp, "Content-Length", hdrval, sizeof (hdrval)))
+    contlen = strtol (hdrval, NULL, 10);
+  type = response_header_strdup (resp, "Content-Type");
+  if (type)
+    {
+      char *tmp = strchr (type, ';');
+      if (tmp)
 	{
-	  xfree (hdr);
-	  break;
+	  while (tmp > type && ISSPACE (tmp[-1]))
+	    --tmp;
+	  *tmp = '\0';
 	}
+    }
+  hs->newloc = response_header_strdup (resp, "Location");
+  hs->remote_time = response_header_strdup (resp, "Last-Modified");
+  set_cookie = response_header_strdup (resp, "Set-Cookie");
+  if (set_cookie)
+    {
+      /* The jar should have been created by now. */
+      assert (wget_cookie_jar != NULL);
+      cookie_handle_set_cookie (wget_cookie_jar, u->host, u->port, u->path,
+				set_cookie);
+      xfree (set_cookie);
+    }
+  authenticate_h = response_header_strdup (resp, "WWW-Authenticate");
+  if (response_header_copy (resp, "Content-Range", hdrval, sizeof (hdrval)))
+    {
+      long first_byte_pos, last_byte_pos, entity_length;
+      if (parse_content_range (hdrval, &first_byte_pos, &last_byte_pos,
+			       &entity_length))
+	contrange = first_byte_pos;
+    }
 
-      /* Print the header if requested.  */
-      if (opt.server_response && hcount != 1)
-	logprintf (LOG_VERBOSE, "\n%2d %s", hcount, hdr);
-
-      /* Try getting content-length.  */
-      if (contlen == -1 && !opt.ignore_length)
-	if (header_process (hdr, "Content-Length", header_extract_number,
-			    &contlen))
-	  goto done_header;
-      /* Try getting content-type.  */
-      if (!type)
-	if (header_process (hdr, "Content-Type", http_process_type, &type))
-	  goto done_header;
-      /* Try getting location.  */
-      if (!hs->newloc)
-	if (header_process (hdr, "Location", header_strdup, &hs->newloc))
-	  goto done_header;
-      /* Try getting last-modified.  */
-      if (!hs->remote_time)
-	if (header_process (hdr, "Last-Modified", header_strdup,
-			    &hs->remote_time))
-	  goto done_header;
-      /* Try getting cookies. */
-      if (opt.cookies)
-	if (header_process (hdr, "Set-Cookie", http_process_set_cookie, u))
-	  goto done_header;
-      /* Try getting www-authentication.  */
-      if (!authenticate_h)
-	if (header_process (hdr, "WWW-Authenticate", header_strdup,
-			    &authenticate_h))
-	  goto done_header;
-      /* Check for accept-ranges header.  If it contains the word
-	 `none', disable the ranges.  */
-      if (*dt & ACCEPTRANGES)
-	{
-	  int nonep;
-	  if (header_process (hdr, "Accept-Ranges", http_process_none, &nonep))
-	    {
-	      if (nonep)
-		*dt &= ~ACCEPTRANGES;
-	      goto done_header;
-	    }
-	}
-      /* Try getting content-range.  */
-      if (contrange == -1)
-	{
-	  struct http_process_range_closure closure;
-	  if (header_process (hdr, "Content-Range", http_process_range, &closure))
-	    {
-	      contrange = closure.first_byte_pos;
-	      goto done_header;
-	    }
-	}
-      /* Check for keep-alive related responses. */
-      if (!inhibit_keep_alive)
+  /* Check for keep-alive related responses. */
+  if (!inhibit_keep_alive && contlen != -1)
+    {
+      if (response_header_copy (resp, "Keep-Alive", NULL, 0))
+	keep_alive = 1;
+      else if (response_header_copy (resp, "Connection", hdrval,
+				     sizeof (hdrval)))
 	{
-	  /* Check for the `Keep-Alive' header. */
-	  if (!http_keep_alive_1)
-	    {
-	      if (header_process (hdr, "Keep-Alive", header_exists,
-				  &http_keep_alive_1))
-		goto done_header;
-	    }
-	  /* Check for `Connection: Keep-Alive'. */
-	  if (!http_keep_alive_2)
-	    {
-	      if (header_process (hdr, "Connection", http_process_connection,
-				  &http_keep_alive_2))
-		goto done_header;
-	    }
+	  if (0 == strcasecmp (hdrval, "Keep-Alive"))
+	    keep_alive = 1;
 	}
-    done_header:
-      xfree (hdr);
     }
-  DEBUGP (("---response end---\n"));
+  response_free (resp);
 
-  logputs (LOG_VERBOSE, "\n");
-
-  if (contlen != -1
-      && (http_keep_alive_1 || http_keep_alive_2))
-    {
-      assert (inhibit_keep_alive == 0);
-      keep_alive = 1;
-    }
   if (keep_alive)
     /* The server has promised that it will not close the connection
        when we're done.  This means that we can register it.  */
