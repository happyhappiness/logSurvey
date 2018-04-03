    {
      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 con->target, strerror (errno));
      xclose (csock);
      rbuf_uninitialize (&con->rbuf);
      return FWRITEERR;
    }
