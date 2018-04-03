  else
    {
      error (NILF, "*** exported to %s (id %u)",
	      host ? host->h_name : inet_ntoa (permit.addr),
	      permit.id);
    }

  fflush (stdout);
