
      if (err && block)
	{
	  /* We might block for a while, so let the user know why.  */
	  fflush (stdout);
	  error (NILF, _("*** Waiting for unfinished jobs...."));
	}

      /* We have one less dead child to reap.  As noted in
