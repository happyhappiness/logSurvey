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
	chmod (con->target, f->perms);
      else
	DEBUGP (("Unrecognized permissions for %s.\n", con->target));

      xfree (con->target);
      con->target = old_target;

      url_set_file (u, ofile);
      xfree (ofile);

      /* Break on fatals.  */
      if (err == QUOTEXC || err == HOSTERR || err == FWRITEERR)
	break;
      con->cmd &= ~ (DO_CWD | DO_LOGIN);
      f = f->next;
    }

  /* We do not want to call ftp_retrieve_dirs here */
  if (opt.recursive &&
      !(opt.reclevel != INFINITE_RECURSION && depth >= opt.reclevel))
