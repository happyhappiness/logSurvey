  else
    {
      logprintf (LOG_VERBOSE, "\n");
      print_server_response (resp, "  ");
    }

  if (statcode == HTTP_STATUS_UNAUTHORIZED)
    {
      /* Authorization is required.  */
      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
				   might be more bytes in the body. */
      if (auth_tried_already || !(user && passwd))
	{
	  /* If we have tried it already, then there is not point
	     retrying it.  */
	  logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
	}
      else
	{
	  char *www_authenticate = response_header_strdup (resp,
							   "WWW-Authenticate");
	  /* If the authentication scheme is unknown or if it's the
	     "Basic" authentication (which we try by default), there's
	     no sense in retrying.  */
	  if (!www_authenticate
	      || !known_authentication_scheme_p (www_authenticate)
	      || BEGINS_WITH (www_authenticate, "Basic"))
	    {
	      xfree_null (www_authenticate);
	      logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
	    }
	  else
	    {
	      char *pth;
	      auth_tried_already = 1;
	      pth = url_full_path (u);
	      request_set_header (req, "Authorization",
				  create_authorization_line (www_authenticate,
							     user, passwd,
							     request_method (req),
							     pth),
				  rel_value);
	      xfree (pth);
	      xfree (www_authenticate);
	      goto retry_with_auth;
	    }
	}
      request_free (req);
      return AUTHFAILED;
    }
  request_free (req);

  hs->statcode = statcode;
  if (statcode == -1)
