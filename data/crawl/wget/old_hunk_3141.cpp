       when we're done.  This means that we can register it.  */
    register_persistent (conn->host, conn->port, sock, using_ssl);

  if ((statcode == HTTP_STATUS_UNAUTHORIZED)
      && authenticate_h)
    {
      /* Authorization is required.  */
      xfree_null (type);
      type = NULL;
      free_hstat (hs);
      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
				   might be more bytes in the body. */
      if (auth_tried_already)
	{
	  /* If we have tried it already, then there is not point
	     retrying it.  */
	failed:
	  logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
	  xfree (authenticate_h);
	  return AUTHFAILED;
	}
      else if (!known_authentication_scheme_p (authenticate_h))
	{
	  xfree (authenticate_h);
	  logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
	  return AUTHFAILED;
	}
      else if (BEGINS_WITH (authenticate_h, "Basic"))
	{
	  /* The authentication scheme is basic, the one we try by
             default, and it failed.  There's no sense in trying
             again.  */
	  goto failed;
	}
      else
	{
	  auth_tried_already = 1;
	  goto again;
	}
    }
  /* We do not need this anymore.  */
  if (authenticate_h)
    {
      xfree (authenticate_h);
      authenticate_h = NULL;
    }

  /* 20x responses are counted among successful by default.  */
  if (H_20X (statcode))
    *dt |= RETROKF;
