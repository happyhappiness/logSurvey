      char *cp;
      char c = '+';

      if (pipe (job_fds) < 0 || (job_rfd = dup (job_fds[0])) < 0)
	pfatal_with_name (_("creating jobs pipe"));

      /* Every make assumes that it always has one job it can run.  For the
         submakes it's the token they were given by their parent.  For the
