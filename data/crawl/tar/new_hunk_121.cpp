  struct name const *cursor;

  for (cursor = namelist; cursor; cursor = cursor->next)
    if (!WASFOUND (cursor) && cursor->name[0])
      {
	regex_usage_warning (cursor->name);
	if (cursor->found_count == 0)
	  ERROR ((0, 0, _("%s: Not found in archive"),
		  quotearg_colon (cursor->name)));
	else
	  ERROR ((0, 0, _("%s: Required occurrence not found in archive"),
		  quotearg_colon (cursor->name)));  
      }

  /* Don't bother freeing the name list; we're about to exit.  */
