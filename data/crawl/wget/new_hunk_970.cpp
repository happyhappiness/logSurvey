
  /* Send preliminary HEAD request if -N is given and we have an existing 
   * destination file. */
  if (opt.timestamping
      && !opt.content_disposition
      && file_exists_p (url_file_name (u)))
    send_head_first = true;

  /* THE loop */
  do
    {
      /* Increment the pass counter.  */
      ++count;
      sleep_between_retrievals (count);

      /* Get the current time string.  */
      tms = datetime_str (time (NULL));

      if (opt.spider && !got_head)
        logprintf (LOG_VERBOSE, _("\
Spider mode enabled. Check if remote file exists.\n"));
