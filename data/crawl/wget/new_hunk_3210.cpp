      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 con->target, strerror (errno));
      fd_close (csock);
      return FWRITEERR;
    }
  else if (res == -1)
