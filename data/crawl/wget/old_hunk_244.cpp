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
