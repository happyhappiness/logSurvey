                   _("WARC output does not work with --spider.\n"));
          exit (1);
        }
      if (opt.always_rest || opt.start_pos >= 0)
        {
          fprintf (stderr,
                   _("WARC output does not work with --continue or"
                     " --start-pos, they will be disabled.\n"));
          opt.always_rest = false;
          opt.start_pos = -1;
        }
      if (opt.warc_cdx_dedup_filename != 0 && !opt.warc_digests_enabled)
        {
