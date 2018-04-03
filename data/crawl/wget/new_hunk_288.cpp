  warc_current_file = fopen (new_filename, "wb+");
  if (warc_current_file == NULL)
    {
      logprintf (LOG_NOTQUIET, _("Error opening WARC file %s.\n"),
                 quote (new_filename));
      return false;
    }

