      if (opt.quota && total_downloaded_bytes > opt.quota)
        logprintf (LOG_NOTQUIET,
                   _("Download quota of %s EXCEEDED!\n"),
                   human_readable (opt.quota));
    }

  if (opt.cookies_output)
