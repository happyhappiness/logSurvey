
  set_content_type (dt, type);

  if (cond_get)
    {
      if (statcode == HTTP_STATUS_NOT_MODIFIED)
        {
          logprintf (LOG_VERBOSE,
                     _ ("File %s not modified on server. Omitting download.\n\n"),
                     quote (hs->local_file));
          *dt |= RETROKF;
          CLOSE_FINISH (sock);
          retval = RETRUNNEEDED;
          goto cleanup;
        }
    }

  if (opt.adjust_extension)
    {
      if (*dt & TEXTHTML)
