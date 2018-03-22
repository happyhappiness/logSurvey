	  size = current_stat.st_size;
	  if (size != current_stat.st_size)
	    FATAL_ERROR ((0, 0, _("Memory exhausted")));
	  bp = *longp = (char *) xmalloc (size);

	  for (; size > 0; size -= written)
	    {
	      data_block = find_next_block ();
	      if (data_block == NULL)
		{
		  ERROR ((0, 0, _("Unexpected EOF on archive file")));
		  break;
