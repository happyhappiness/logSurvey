      if (retr_err != RETROK)
        {
          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
                     quote (destname ? destname : filename));
        }
      else if (!hash_ok)
        {
