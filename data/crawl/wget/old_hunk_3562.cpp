		fl = opt.output_document;
	    }
	  else
	    fl = u->local;
	  if (fl)
	    touch (fl, f->tstamp);
	}
      else if (f->tstamp == -1)
	logprintf (LOG_NOTQUIET, _("%s: corrupt time-stamp.\n"), u->local);

      if (f->perms && f->type == FT_PLAINFILE && dlthis)
	chmod (u->local, f->perms);
      else
	DEBUGP (("Unrecognized permissions for %s.\n", u->local));

      xfree (u->local);
      u->local = olocal;
      u->file = ofile;
      /* Break on fatals.  */
      if (err == QUOTEXC || err == HOSTERR || err == FWRITEERR)
	break;
      con->cmd &= ~ (DO_CWD | DO_LOGIN);
      f = f->next;
    } /* while */
  /* We do not want to call ftp_retrieve_dirs here */
  if (opt.recursive &&
      !(opt.reclevel != INFINITE_RECURSION && depth >= opt.reclevel))
