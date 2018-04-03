          /* No luck.  */
          /* #### This message SUCKS.  We should see what was the
             reason that nothing was retrieved.  */
          logprintf (LOG_VERBOSE, _("No matches on pattern %s.\n"),
                     quote (escnonprint (u->file)));
        }
      else /* GLOB_GETONE or GLOB_GETALL */
        {
