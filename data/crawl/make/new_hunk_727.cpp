
      if (err && block)
	{
          static int printed = 0;

	  /* We might block for a while, so let the user know why.
             Only print this message once no matter how many jobs are left.  */
	  fflush (stdout);
          if (!printed)
            error (NILF, _("*** Waiting for unfinished jobs...."));
          printed = 1;
	}

      /* We have one less dead child to reap.  As noted in
