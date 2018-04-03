#endif /* HAVE_SSL */
      )
    {
      struct address_list *al = lookup_host (conn->host, 0);
      if (!al)
	return HOSTERR;
      set_connection_host_name (conn->host);
      sock = connect_to_many (al, conn->port, 0);
      set_connection_host_name (NULL);
      address_list_release (al);

      if (sock < 0)
	return errno == ECONNREFUSED ? CONREFUSED : CONERROR;

#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       if (connect_ssl (&ssl, ssl_ctx,sock) != 0)
