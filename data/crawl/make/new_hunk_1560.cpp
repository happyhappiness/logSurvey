      error ("CUSTOMS_IMPORT: %s", msg);
      return 1;
    }
  else if (debug_flag)
    {
      struct hostent *host = gethostbyaddr (&permit.addr, sizeof (permit.addr),
					    AF_INET);
      printf ("Job exported to %s ID %u\n",
	      host == 0 ? inet_ntoa (permit.addr) : host->h_name,
	      permit.id);
    }

  fflush (stdout);
  fflush (stderr);
