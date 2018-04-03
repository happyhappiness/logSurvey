  tmrate = retr_rate (rd_size, con->dltime);
  total_download_time += con->dltime;

  fd_close (local_sock);
  /* Close the local file.  */
  if (!output_stream || con->cmd & DO_LIST)
    fclose (fp);

  /* If fd_read_body couldn't write to fp, bail out.  */
  if (res == -2)
    {
      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
		 con->target, strerror (errno));
      fd_close (csock);
      con->csock = -1;
      fd_close (dtsock);
      return FWRITEERR;
    }
  else if (res == -1)
    {
      logprintf (LOG_NOTQUIET, _("%s (%s) - Data connection: %s; "),
		 tms, tmrate, fd_errstr (dtsock));
      if (opt.server_response)
	logputs (LOG_ALWAYS, "\n");
    }
  fd_close (dtsock);

  /* Get the server to tell us if everything is retrieved.  */
  err = ftp_response (csock, &respline);
