
  if (cond_get)
    {
      if (statcode == HTTP_STATUS_NOT_MODIFIED)
        {
          logprintf (LOG_VERBOSE,
                     _("File %s not modified on server. Omitting download.\n\n"),
                     quote (hs->local_file));
          *dt |= RETROKF;
          CLOSE_FINISH (sock);
          retval = RETRUNNEEDED;
          goto cleanup;
        }
      /* Handle the case when server ignores If-Modified-Since header.  */
      else if (statcode == HTTP_STATUS_OK && hs->remote_time)
        {
          time_t tmr = http_atotm (hs->remote_time);

