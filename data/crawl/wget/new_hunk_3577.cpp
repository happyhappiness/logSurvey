      if (opt.spider)
	{
	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode, hstat.error);
	  FREE_MAYBE (dummy);
	  return RETROK;
	}

      tmrate = rate (hstat.len - hstat.restval, hstat.dltime, 0);

      if (hstat.len == hstat.contlen)
