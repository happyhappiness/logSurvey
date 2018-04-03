          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
                     quote (destname ? destname : safename));
        }
      else if (!hash_ok)
        {
          retr_err = METALINK_CHKSUM_ERROR;
