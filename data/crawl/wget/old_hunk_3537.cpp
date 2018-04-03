	--line_end;
      if (line_end > line_beg)
	{
	  urlpos *entry = (urlpos *)xmalloc (sizeof (urlpos));
	  memset (entry, 0, sizeof (*entry));
	  entry->next = NULL;
	  entry->url = strdupdelim (line_beg, line_end);
	  if (!head)
	    head = entry;
	  else
