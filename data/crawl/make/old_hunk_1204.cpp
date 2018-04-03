
#ifdef MAKE_JOBSERVER
  /* If extended jobs are available then the -j option can have one of 4
     formats: (1) not specified: default is "1"; (2) specified with no
     value: default is "0" (infinite); (3) specified with a single
     value: this means the user wants N job slots; or (4) specified with
     2 values separated by commas.  The latter means we're a submake and
     the two values are the read and write FDs, respectively, for the
     pipe.  Note this last form is undocumented for the user!
   */
  sscanf(job_slots_str, "%d", &job_slots);
  {
    char *cp = index(job_slots_str, ',');

    if (cp && sscanf(cp+1, "%d", &job_fds[1]) == 1)
      {
	job_fds[0] = job_slots;
	job_slots = 0;
      }
  }

