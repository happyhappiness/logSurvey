      total_downloaded_bytes != 0)
    {
      logprintf (LOG_NOTQUIET,
		 _("FINISHED --%s--\nDownloaded: %d files, %s in %s (%s)\n"),
		 time_str (NULL),
		 opt.numurls,
		 human_readable (total_downloaded_bytes),
		 secs_to_human_time (total_download_time),
		 retr_rate (total_downloaded_bytes, total_download_time));
      /* Print quota warning, if exceeded.  */
      if (opt.quota && total_downloaded_bytes > opt.quota)
	logprintf (LOG_NOTQUIET,
		   _("Download quota of %s EXCEEDED!\n"),
		   human_readable (opt.quota));
    }

  if (opt.cookies_output)
