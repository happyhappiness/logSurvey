	  request_free (connreq);
	  if (write_error < 0)
	    {
	      logprintf (LOG_VERBOSE, _("Failed writing to proxy: %s.\n"),
			 fd_errstr (sock));
	      CLOSE_INVALIDATE (sock);
	      return WRITEFAILED;
	    }
