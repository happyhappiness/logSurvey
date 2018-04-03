      if (resolve_bind_address (opt.bind_address, bind_sa, 0))
	{
          if (bind (sock, bind_sa, sockaddr_size (bind_sa)) < 0)
	    goto err;
	}
    }

  /* Connect the socket to the remote endpoint.  */
  if (connect_with_timeout (sock, sa, sockaddr_size (sa),
			    opt.connect_timeout) < 0)
    goto err;

  /* Success. */
  assert (sock >= 0);
  if (print)
    logprintf (LOG_VERBOSE, _("connected.\n"));
  DEBUGP (("Created socket %d.\n", sock));
  return sock;

 err:
  {
    /* Protect errno from possible modifications by close and
       logprintf.  */
    int save_errno = errno;
    if (sock >= 0)
      CLOSE (sock);
    if (print)
      logprintf (LOG_VERBOSE, "failed: %s.\n", strerror (errno));
    errno = save_errno;
    return -1;
  }
}

/* Connect to a remote endpoint specified by host name.  */
