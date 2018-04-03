  /* Print the downloaded sum.  */
  if (opt.recursive
      || nurl > 1
      || (opt.input_filename && total_downloaded_bytes != 0))
    {
      logprintf (LOG_NOTQUIET,
		 _("\nFINISHED --%s--\nDownloaded: %s bytes in %d files\n"),
		 time_str (NULL), legible_large_int (total_downloaded_bytes),
		 opt.numurls);
      /* Print quota warning, if exceeded.  */
      if (opt.quota && total_downloaded_bytes > opt.quota)
	logprintf (LOG_NOTQUIET,
		   _("Download quota (%s bytes) EXCEEDED!\n"),
		   legible (opt.quota));
