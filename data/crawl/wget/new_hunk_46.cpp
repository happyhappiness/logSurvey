            } /* endif RETR_OK.  */
        } /* Iterate over resources.  */

      if (!mfile->checksums)
        {
          logprintf (LOG_NOTQUIET, _("No checksums found.\n"));
          retr_err = METALINK_CHKSUM_ERROR;
        }

      if (retr_err != RETROK)
        {
          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
