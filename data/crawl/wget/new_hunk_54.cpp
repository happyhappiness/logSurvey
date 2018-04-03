          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
                     quote (destname ? destname : safename));
        }
      else if (!size_ok)
        {
          retr_err = METALINK_SIZE_ERROR;
          logprintf (LOG_NOTQUIET,
                     _("File %s retrieved but size does not match. "
                       "\n"), quote (destname));
        }
      else if (!hash_ok)
        {
          retr_err = METALINK_CHKSUM_ERROR;
