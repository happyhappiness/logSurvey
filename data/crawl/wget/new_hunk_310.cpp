  if (!output_stream || con->cmd & DO_LIST)
    fclose (fp);

  /* If fd_read_body couldn't write to fp or warc_tmp, bail out.  */
  if (res == -2 || (warc_tmp != NULL && res == -3))
    {
      logprintf (LOG_NOTQUIET, _("%s: %s, closing control connection.\n"),
                 con->target, strerror (errno));
      fd_close (csock);
      con->csock = -1;
      fd_close (dtsock);
      if (res == -2)
        return FWRITEERR;
      else if (res == -3)
        return WARC_TMP_FWRITEERR;
    }
  else if (res == -1)
    {
