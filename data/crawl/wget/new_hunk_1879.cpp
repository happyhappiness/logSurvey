        logputs (LOG_VERBOSE, _("==> CWD not needed.\n"));
      else
        {
          char *targ;
	  int cwd_count;
	  int cwd_end;
	  int cwd_start;

          char *target = u->dir;

          DEBUGP (("changing working directory\n"));
