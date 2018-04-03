
      if (warc_current_gzfile == NULL)
        {
          logprintf (LOG_NOTQUIET, _("Error opening GZIP stream to WARC file.\n"));
          warc_write_ok = false;
          return false;
        }
