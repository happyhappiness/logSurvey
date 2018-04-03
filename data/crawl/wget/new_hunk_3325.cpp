	      logprintf (LOG_VERBOSE, "==> RETR %s ... ", u->file);
	    }
	}

      err = ftp_retr (&con->rbuf, u->file);
      /* FTPRERR, WRITEFAILED, FTPNSFOD */
      switch (err)
