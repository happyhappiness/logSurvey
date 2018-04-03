           }
    }

  if (opt.warc_filename != 0)
    {
      if (opt.noclobber)
        {
          fprintf (stderr,
                   _("WARC output does not work with --no-clobber, "
                     "--no-clobber will be disabled.\n"));
          opt.noclobber = false;
        }
      if (opt.timestamping)
        {
          fprintf (stderr,
                   _("WARC output does not work with timestamping, "
                     "timestamping will be disabled.\n"));
          opt.timestamping = false;
        }
      if (opt.spider)
        {
          fprintf (stderr,
                   _("WARC output does not work with --spider.\n"));
          exit (1);
        }
      if (opt.always_rest)
        {
          fprintf (stderr,
                   _("WARC output does not work with --continue, "
                     "--continue will be disabled.\n"));
          opt.always_rest = false;
        }
      if (opt.warc_cdx_dedup_filename != 0 && !opt.warc_digests_enabled)
        {
          fprintf (stderr,
                   _("Digests are disabled; WARC deduplication will "
                     "not find duplicate records.\n"));
        }
      if (opt.warc_keep_log)
        {
          opt.progress_type = "dot";
        }
    }

  if (opt.ask_passwd && opt.passwd)
    {
      fprintf (stderr,
