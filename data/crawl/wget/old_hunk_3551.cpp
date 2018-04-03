	    {
	      logprintf (LOG_NOTQUIET,
			 _("\nREST failed; will not truncate `%s'.\n"),
			 u->local);
	      CLOSE (csock);
	      closeport (dtsock);
	      rbuf_uninitialize (&con->rbuf);
