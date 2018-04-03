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
