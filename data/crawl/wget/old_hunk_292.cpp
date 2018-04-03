          warc_log_fp = warc_tempfile ();
          if (warc_log_fp == NULL)
            {
              logprintf (LOG_NOTQUIET, _("Could not open temporary WARC log file.\n"));
              exit(1);
            }
          log_set_warc_log_fp (warc_log_fp);
