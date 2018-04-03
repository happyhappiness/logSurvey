          logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"),
                     escnonprint (u->file));
        }
      else /* GLOB_GETONE or GLOB_GETALL */
        {
          /* Let's try retrieving it anyway.  */
          con->st |= ON_YOUR_OWN;
          res = ftp_loop_internal (u, NULL, con);
          return res;
        }
    }
  freefileinfo (start);
  if (opt.quota && total_downloaded_bytes > opt.quota)
