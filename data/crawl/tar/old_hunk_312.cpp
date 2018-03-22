void
names_notfound (void)
{
  struct name *cursor;
  struct name *next;

  for (cursor = namelist; cursor; cursor = next)
    {
      next = cursor->next;
      if (!cursor->found && !cursor->fake)
	ERROR ((0, 0, _("%s: Not found in archive"),
		quotearg_colon (cursor->name)));

      /* We could free the list, but the process is about to die anyway, so
	 save some CPU time.  Amigas and other similarly broken software
	 will need to waste the time, though.  */

#ifdef amiga
      if (!same_order_option)
	free (cursor);
#endif
    }
  namelist = 0;
  nametail = &namelist;

