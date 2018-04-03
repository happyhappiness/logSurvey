          break;
        }       /* switch */

      /* Set the time-stamp information to the local file.  Symlinks
         are not to be stamped because it sets the stamp on the
         original.  :( */
      if (!(f->type == FT_SYMLINK && !opt.retr_symlinks)
          && f->tstamp != -1
          && dlthis
          && file_exists_p (con->target))
        {
          /* #### This code repeats in http.c and ftp.c.  Move it to a
             function!  */
          const char *fl = NULL;
          if (opt.output_document)
            {
              if (output_stream_regular)
                fl = opt.output_document;
            }
          else
            fl = con->target;
          if (fl)
            touch (fl, f->tstamp);
        }
      else if (f->tstamp == -1)
        logprintf (LOG_NOTQUIET, _("%s: corrupt time-stamp.\n"), con->target);

      if (f->perms && f->type == FT_PLAINFILE && dlthis)
        {
          if (opt.preserve_perm)
            chmod (con->target, f->perms);
        }
      else
        DEBUGP (("Unrecognized permissions for %s.\n", con->target));

      xfree (con->target);
      con->target = old_target;
