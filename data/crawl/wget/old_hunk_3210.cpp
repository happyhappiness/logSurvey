      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 con->target, strerror (errno));
      fd_close (csock);
      rbuf_uninitialize (&con->rbuf);
      return FWRITEERR;
    }
  else if (res == -1)
