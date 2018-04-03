      ++count;
      sleep_between_retrievals (count);
      if (con->st & ON_YOUR_OWN)
        {
          con->cmd = 0;
          con->cmd |= (DO_RETR | LEAVE_PENDING);
          if (con->csock != -1)
            con->cmd &= ~ (DO_LOGIN | DO_CWD);
          else
            con->cmd |= (DO_LOGIN | DO_CWD);
        }
      else /* not on your own */
        {
          if (con->csock != -1)
            con->cmd &= ~DO_LOGIN;
          else
            con->cmd |= DO_LOGIN;
          if (con->st & DONE_CWD)
            con->cmd &= ~DO_CWD;
          else
            con->cmd |= DO_CWD;
        }

      /* Decide whether or not to restart.  */
      if (opt.always_rest
          && stat (locf, &st) == 0
          && S_ISREG (st.st_mode))
        /* When -c is used, continue from on-disk size.  (Can't use
           hstat.len even if count>1 because we don't want a failed
           first attempt to clobber existing data.)  */
        restval = st.st_size;
      else if (count > 1)
        restval = len;          /* start where the previous run left off */
      else
        restval = 0;

      /* Get the current time string.  */
      tms = time_str (time (NULL));
      /* Print fetch message, if opt.verbose.  */
      if (opt.verbose)
        {
          char *hurl = url_string (u, URL_AUTH_HIDE_PASSWD);
          char tmp[256];
          strcpy (tmp, "        ");
          if (count > 1)
            sprintf (tmp, _("(try:%2d)"), count);
          logprintf (LOG_VERBOSE, "--%s--  %s\n  %s => `%s'\n",
                     tms, hurl, tmp, locf);
#ifdef WINDOWS
          ws_changetitle (hurl);
#endif
          xfree (hurl);
        }
      /* Send getftp the proper length, if fileinfo was provided.  */
      if (f)
        len = f->size;
      else
        len = 0;
      err = getftp (u, &len, restval, con);

      if (con->csock == -1)
        con->st &= ~DONE_CWD;
      else
        con->st |= DONE_CWD;

      switch (err)
        {
        case HOSTERR: case CONIMPOSSIBLE: case FWRITEERR: case FOPENERR:
        case FTPNSFOD: case FTPLOGINC: case FTPNOPASV: case CONTNOTSUPPORTED:
          /* Fatal errors, give up.  */
          return err;
        case CONSOCKERR: case CONERROR: case FTPSRVERR: case FTPRERR:
        case WRITEFAILED: case FTPUNKNOWNTYPE: case FTPSYSERR:
        case FTPPORTERR: case FTPLOGREFUSED: case FTPINVPASV:
        case FOPEN_EXCL_ERR:
          printwhat (count, opt.ntry);
          /* non-fatal errors */
          if (err == FOPEN_EXCL_ERR)
            {
              /* Re-determine the file name. */
              xfree_null (con->target);
              con->target = url_file_name (u);
              locf = con->target;
            }
          continue;
        case FTPRETRINT:
          /* If the control connection was closed, the retrieval
             will be considered OK if f->size == len.  */
          if (!f || len != f->size)
            {
              printwhat (count, opt.ntry);
              continue;
            }
          break;
        case RETRFINISHED:
          /* Great!  */
          break;
        default:
          /* Not as great.  */
          abort ();
        }
      tms = time_str (time (NULL));
      if (!opt.spider)
        tmrate = retr_rate (len - restval, con->dltime);

      /* If we get out of the switch above without continue'ing, we've
         successfully downloaded a file.  Remember this fact. */
      downloaded_file (FILE_DOWNLOADED_NORMALLY, locf);

      if (con->st & ON_YOUR_OWN)
        {
          fd_close (con->csock);
          con->csock = -1;
        }
      if (!opt.spider)
        logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%s]\n\n"),
                   tms, tmrate, locf, number_to_static_string (len));
      if (!opt.verbose && !opt.quiet)
        {
          /* Need to hide the password from the URL.  The `if' is here
             so that we don't do the needless allocation every
             time. */
          char *hurl = url_string (u, URL_AUTH_HIDE_PASSWD);
          logprintf (LOG_NONVERBOSE, "%s URL: %s [%s] -> \"%s\" [%d]\n",
                     tms, hurl, number_to_static_string (len), locf, count);
          xfree (hurl);
        }

      if ((con->cmd & DO_LIST))
        /* This is a directory listing file. */
        {
          if (!opt.remove_listing)
            /* --dont-remove-listing was specified, so do count this towards the
               number of bytes and files downloaded. */
            {
              total_downloaded_bytes += len;
              opt.numurls++;
            }

          /* Deletion of listing files is not controlled by --delete-after, but
             by the more specific option --dont-remove-listing, and the code
             to do this deletion is in another function. */
        }
      else if (!opt.spider)
        /* This is not a directory listing file. */
        {
          /* Unlike directory listing files, don't pretend normal files weren't
             downloaded if they're going to be deleted.  People seeding proxies,
             for instance, may want to know how many bytes and files they've
             downloaded through it. */
          total_downloaded_bytes += len;
          opt.numurls++;

          if (opt.delete_after)
            {
              DEBUGP (("\
Removing file due to --delete-after in ftp_loop_internal():\n"));
              logprintf (LOG_VERBOSE, _("Removing %s.\n"), locf);
              if (unlink (locf))
                logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
            }
        }

      /* Restore the original leave-pendingness.  */
      if (orig_lp)
        con->cmd |= LEAVE_PENDING;
      else
        con->cmd &= ~LEAVE_PENDING;
      return RETROK;
    } while (!opt.ntry || (count < opt.ntry));

