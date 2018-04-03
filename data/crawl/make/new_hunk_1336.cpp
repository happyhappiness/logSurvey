    {
      (void) close (retsock);
      (void) close (sock);
      error (NILF, "exporting to %s: %s",
             host ? host->h_name : inet_ntoa (permit.addr),
             msg);
      return 1;
    }
  else
    {
      error (NILF, "*** exported to %s (id %u)",
	      host ? host->h_name : inet_ntoa (permit.addr),
	      permit.id);
    }
