		? CONERROR : CONIMPOSSIBLE);

#ifdef HAVE_SSL
      if (proxy && u->scheme == SCHEME_HTTPS)
	{
	  /* When requesting SSL URLs through proxies, use the
	     CONNECT method to request passthrough.  */
	  char *connect =
	    (char *) alloca (64
			     + strlen (u->host)
			     + (proxyauth ? strlen (proxyauth) : 0));
	  sprintf (connect, "CONNECT %s:%d HTTP/1.0\r\n%s\r\n",
		   u->host, u->port, proxyauth ? proxyauth : "");
	  DEBUGP (("Writing to proxy: [%s]\n", connect));
	  write_error = fd_write (sock, connect, strlen (connect), -1);
	  if (write_error < 0)
	    {
	      xfree_null (proxyauth);
	      logprintf (LOG_VERBOSE, _("Failed writing to proxy: %s.\n"),
			 strerror (errno));
	      CLOSE_INVALIDATE (sock);
	      return WRITEFAILED;
	    }

	  head = fd_read_http_head (sock);
	  if (!head)
	    {
	      xfree_null (proxyauth);
	      logprintf (LOG_VERBOSE, _("Failed reading proxy response: %s\n"),
			 strerror (errno));
	      CLOSE_INVALIDATE (sock);
	      return HERR;
	    }
	  message = NULL;
	  if (!*head)
	    {
	      xfree (head);
	      goto failed_tunnel;
	    }
	  DEBUGP (("proxy responded with: [%s]\n", head));

	  resp = response_new (head);
	  statcode = response_status (resp, &message);
	  response_free (resp);
	  if (statcode != 200)
	    {
	    failed_tunnel:
	      xfree_null (proxyauth);
	      logprintf (LOG_NOTQUIET, _("Proxy tunneling failed: %s"),
			 message ? message : "?");
	      xfree_null (message);
	      return CONSSLERR;
	    }
	  xfree (message);

	  /* SOCK is now *really* connected to u->host, so update CONN
	     to reflect this.  That way register_persistent will
	     register SOCK as being connected to u->host:u->port.  */
	  conn = u;
	}

      if (conn->scheme == SCHEME_HTTPS)
	{
	  if (!ssl_connect (sock))
	    {
	      fd_close (sock);
	      return CONSSLERR;
	    }
	  using_ssl = 1;
	}
#endif /* HAVE_SSL */
    }

  if (*dt & HEAD_ONLY)
    command = "HEAD";
