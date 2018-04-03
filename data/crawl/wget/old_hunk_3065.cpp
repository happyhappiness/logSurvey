
      if (opt.spider)
	{
	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode, hstat.error);
	  xfree_null (dummy);
	  return RETROK;
	}
