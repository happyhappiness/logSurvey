
  if (stat (file->name, &st) == 0
      && S_ISREG (st.st_mode)
      && (time_t) st.st_mtime != file->last_mtime)
    {
      if (on_behalf_of)
	error ("*** [%s] Deleting file `%s'", on_behalf_of, file->name);
      else
	error ("*** Deleting file `%s'", file->name);
      if (unlink (file->name) < 0
	  && errno != ENOENT)	/* It disappeared; so what.  */
	perror_with_name ("unlink: ", file->name);
