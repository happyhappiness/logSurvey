
  if (opt.cookies)
    request_set_header (req, "Cookie",
			cookie_header (wget_cookie_jar,
				       u->host, u->port, u->path,
#ifdef HAVE_SSL
				       u->scheme == SCHEME_HTTPS
#else
				       0
#endif
				       ),
			rel_value);

  if (opt.post_data || opt.post_file_name)
    {
      request_set_header (req, "Content-Type",
			  "application/x-www-form-urlencoded", rel_none);
      if (opt.post_data)
	post_data_size = strlen (opt.post_data);
      else
	{
	  post_data_size = file_size (opt.post_file_name);
	  if (post_data_size == -1)
	    {
	      logprintf (LOG_NOTQUIET, _("POST data file `%s' missing: %s\n"),
			 opt.post_file_name, strerror (errno));
	      post_data_size = 0;
	    }
	}
      request_set_header (req, "Content-Length",
			  xstrdup (number_to_static_string (post_data_size)),
			  rel_value);
    }

  /* Add the user headers. */
