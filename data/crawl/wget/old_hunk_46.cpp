            } /* endif RETR_OK.  */
        } /* Iterate over resources.  */

      if (retr_err != RETROK)
        {
          logprintf (LOG_VERBOSE, _("Failed to download %s. Skipping resource.\n"),
