	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", u->file);
	}

      err = ftp_size(csock, u->file, len);
      /* FTPRERR */
      switch (err)
	{
