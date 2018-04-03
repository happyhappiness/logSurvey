      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 con->target, strerror (errno));
      fd_close (csock);
      con->csock = -1;
      return FWRITEERR;
    }
  else if (res == -1)
