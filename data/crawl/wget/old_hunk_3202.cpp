	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", u->file);
	}

      err = ftp_size(&con->rbuf, u->file, len);
      /* FTPRERR */
      switch (err)
	{
