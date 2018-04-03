      if (opt.verbose)
	{
          if (!opt.server_response)
	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", u->file);
	}

      err = ftp_size (csock, u->file, len);
