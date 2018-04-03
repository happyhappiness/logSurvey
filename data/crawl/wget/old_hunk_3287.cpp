      if (resolve_bind_address (opt.bind_address, bind_sa, 0))
	{
          if (bind (sock, bind_sa, sockaddr_size (bind_sa)) < 0)
	    {
	      CLOSE (sock);
	      sock = -1;
	      goto out;
	    }
	}
    }

  /* Connect the socket to the remote endpoint.  */
  if (connect_with_timeout (sock, sa, sockaddr_size (sa),
			    opt.connect_timeout) < 0)
    {
      CLOSE (sock);
      sock = -1;
      goto out;
    }

 out:
  if (sock >= 0)
    {
      /* Success. */
      if (print)
	logprintf (LOG_VERBOSE, _("connected.\n"));
      DEBUGP (("Created socket %d.\n", sock));
    }
  else
    {
      save_errno = errno;
      if (print)
	logprintf (LOG_VERBOSE, "failed: %s.\n", strerror (errno));
      errno = save_errno;
    }

  return sock;
}

/* Connect to a remote endpoint specified by host name.  */
