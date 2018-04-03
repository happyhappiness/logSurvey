	  abort ();
	}
	if (!opt.server_response)
	  logputs (LOG_VERBOSE, _("done.\n"));
    }

  /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
