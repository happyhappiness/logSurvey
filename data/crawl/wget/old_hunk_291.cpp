      warc_manifest_fp = warc_tempfile ();
      if (warc_manifest_fp == NULL)
        {
          logprintf (LOG_NOTQUIET, _("Could not open temporary WARC manifest file.\n"));
          exit(1);
        }

