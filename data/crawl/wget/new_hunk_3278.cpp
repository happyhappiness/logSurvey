      if (!fp)
	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
	  xclose (csock);
	  rbuf_uninitialize (&con->rbuf);
	  xclose (dtsock);
	  xclose (local_sock);
	  return FOPENERR;
	}
    }
