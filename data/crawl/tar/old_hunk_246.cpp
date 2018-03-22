  struct name const *cursor;

  for (cursor = namelist; cursor; cursor = cursor->next)
    if (!cursor->found && !cursor->fake)
      ERROR ((0, 0, _("%s: Not found in archive"),
	      quotearg_colon (cursor->name)));

  /* Don't bother freeing the name list; we're about to exit.  */
  namelist = 0;
  nametail = &namelist;
