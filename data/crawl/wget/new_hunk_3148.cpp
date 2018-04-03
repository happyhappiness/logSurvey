	}
    }

  DEBUGP (("\n---response begin---\n"));
  DEBUGP (("%s", head));
  DEBUGP (("---response end---\n"));

  resp = response_new (head);

  /* Check for status line.  */
  message = NULL;
  statcode = response_status (resp, &message);
  if (!opt.server_response)
    logprintf (LOG_VERBOSE, "%2d %s\n", statcode, message ? message : "");
  else
    {
      logprintf (LOG_VERBOSE, "\n");
      print_server_response (resp);
    }

  hs->statcode = statcode;
  if (statcode == -1)
    hs->error = xstrdup (_("Malformed status line"));
  else if (!*message)
    hs->error = xstrdup (_("(no description)"));
  else
    hs->error = xstrdup (message);

  if (response_header_copy (resp, "Content-Length", hdrval, sizeof (hdrval)))
    contlen = strtol (hdrval, NULL, 10);
  type = response_header_strdup (resp, "Content-Type");
  if (type)
    {
      char *tmp = strchr (type, ';');
      if (tmp)
	{
	  while (tmp > type && ISSPACE (tmp[-1]))
	    --tmp;
	  *tmp = '\0';
	}
    }
  hs->newloc = response_header_strdup (resp, "Location");
  hs->remote_time = response_header_strdup (resp, "Last-Modified");
  set_cookie = response_header_strdup (resp, "Set-Cookie");
  if (set_cookie)
    {
      /* The jar should have been created by now. */
      assert (wget_cookie_jar != NULL);
      cookie_handle_set_cookie (wget_cookie_jar, u->host, u->port, u->path,
				set_cookie);
      xfree (set_cookie);
    }
  authenticate_h = response_header_strdup (resp, "WWW-Authenticate");
  if (response_header_copy (resp, "Content-Range", hdrval, sizeof (hdrval)))
    {
      long first_byte_pos, last_byte_pos, entity_length;
      if (parse_content_range (hdrval, &first_byte_pos, &last_byte_pos,
			       &entity_length))
	contrange = first_byte_pos;
    }

  /* Check for keep-alive related responses. */
  if (!inhibit_keep_alive && contlen != -1)
    {
      if (response_header_copy (resp, "Keep-Alive", NULL, 0))
	keep_alive = 1;
      else if (response_header_copy (resp, "Connection", hdrval,
				     sizeof (hdrval)))
	{
	  if (0 == strcasecmp (hdrval, "Keep-Alive"))
	    keep_alive = 1;
	}
    }
  response_free (resp);

  if (keep_alive)
    /* The server has promised that it will not close the connection
       when we're done.  This means that we can register it.  */
