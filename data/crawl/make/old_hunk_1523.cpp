  if (child->deleted)
    return;

  /* Delete the file unless it's precious or not actually a file (phony).  */
  if (!child->file->precious && !child->file->phony
      && stat (child->file->name, &st) == 0
      && S_ISREG (st.st_mode)
      && (time_t) st.st_mtime != child->file->last_mtime)
    {
      error ("*** Deleting file `%s'", child->file->name);
      if (unlink (child->file->name) < 0)
	perror_with_name ("unlink: ", child->file->name);
    }

  /* Also remove any non-precious targets listed
     in the `also_make' member.  */
  for (d = child->file->also_make; d != 0; d = d->next)
    if (!d->file->precious && !d->file->phony)
      if (stat (d->file->name, &st) == 0
	  && S_ISREG (st.st_mode)
	  && (time_t) st.st_mtime != d->file->last_mtime)
	{
	  error ("*** [%s] Deleting file `%s'", child->file->name,
		 d->file->name);
	  if (unlink (d->file->name) < 0)
	    perror_with_name ("unlink: ", d->file->name);
	}

  child->deleted = 1;
}
