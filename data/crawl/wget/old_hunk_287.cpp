  warc_write_end_record ();

  if (! warc_write_ok)
    {
      logprintf (LOG_NOTQUIET, _("Error writing warcinfo record to WARC file.\n"));
    }

  free (filename_copy);
  free (filename_basename);
