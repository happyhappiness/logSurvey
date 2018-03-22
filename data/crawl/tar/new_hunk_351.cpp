    {
      next = cursor->next;
      if (!cursor->found && !cursor->fake)
	ERROR ((0, 0, _("%s: Not found in archive"),
		quotearg_colon (cursor->name)));

      /* We could free the list, but the process is about to die anyway, so
	 save some CPU time.  Amigas and other similarly broken software
