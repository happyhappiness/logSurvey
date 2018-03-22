	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
		_("Time stamp out of range")));
      else
	newer_mtime_option = t;

      while (0 < (n = getline (&buf, &bufsize, fp)))
	{
