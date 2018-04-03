  /* Print the downloaded sum.  */
  if (opt.recursive
      || nurl > 1
      || (opt.input_filename && opt.downloaded != 0))
    {
      logprintf (LOG_NOTQUIET,
		 _("\nFINISHED --%s--\nDownloaded: %s bytes in %d files\n"),
		 time_str (NULL),
		 (opt.downloaded_overflow ?
		  "<overflow>" : legible_very_long (opt.downloaded)),
		 opt.numurls);
      /* Print quota warning, if exceeded.  */
      if (downloaded_exceeds_quota ())
	logprintf (LOG_NOTQUIET,
		   _("Download quota (%s bytes) EXCEEDED!\n"),
		   legible (opt.quota));
