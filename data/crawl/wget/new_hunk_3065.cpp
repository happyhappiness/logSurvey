
      if (opt.spider)
	{
	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
		     escnonprint (hstat.error));
	  xfree_null (dummy);
	  return RETROK;
	}
