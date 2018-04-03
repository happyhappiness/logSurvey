    {
      if (!chain->permanent)
	continue;
      if (chain->expiry_time < cookies_now)
	continue;
      fprintf (fp, "%s\t%s\t%s\t%s\t%lu\t%s\t%s\n",
	       domain, *domain == '.' ? "TRUE" : "FALSE",
	       chain->path, chain->secure ? "TRUE" : "FALSE",
	       chain->expiry_time,
	       chain->attr, chain->value);
      if (ferror (fp))
	return 1;		/* stop mapping */
