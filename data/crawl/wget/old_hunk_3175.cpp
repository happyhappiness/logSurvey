	{
	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
	  fd_close (csock);
	  fd_close (dtsock);
	  fd_close (local_sock);
	  return FOPENERR;
