	}
	else if (strcasecmp ("CacheFlush", key) == 0)
	{
		int tmp = atoi (val);
		if (tmp < 0)
		{
			fprintf (stderr, "rrdtool: `CacheFlush' must "
