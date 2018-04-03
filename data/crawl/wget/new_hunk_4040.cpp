  use_ts = 0;
  if (opt.timestamping)
    {
      boolean  local_file_exists = FALSE;

      if (opt.backup_converted)
	/* If -K is specified, we'll act on the assumption that it was specified
	   last time these files were downloaded as well, and instead of just
	   comparing local file X against server file X, we'll compare local
	   file X.orig (if extant, else X) against server file X.  If -K
	   _wasn't_ specified last time, or the server contains files called
	   *.orig, -N will be back to not operating correctly with -k. */
	{
	  size_t filename_len = strlen(u->local);
	  char*  filename_plus_orig_suffix = malloc(filename_len +
						    sizeof(".orig"));

	  /* Would a single s[n]printf() call be faster? */
	  strcpy(filename_plus_orig_suffix, u->local);
	  strcpy(filename_plus_orig_suffix + filename_len, ".orig");

	  /* Try to stat() the .orig file. */
	  if (stat(filename_plus_orig_suffix, &st) == 0)
	    {
	      local_file_exists = TRUE;
	      local_dot_orig_file_exists = TRUE;
	    }

	  free(filename_plus_orig_suffix);
	}      

      if (!local_dot_orig_file_exists)
	/* Couldn't stat() <file>.orig, so try to stat() <file>. */
	if (stat (u->local, &st) == 0)
	  local_file_exists = TRUE;

      if (local_file_exists)
	/* There was a local file, so we'll check later to see if the version
	   the server has is the same version we already have, allowing us to
	   skip a download. */
	{
	  use_ts = 1;
	  tml = st.st_mtime;
