		}
		cache_timeout = tmp;
	}
	else if (strcasecmp ("CacheFlush", key) == 0)
	{
		int tmp = atoi (val);
		if (tmp < 0)
		{
			fprintf (stderr, "rrdtool: `CacheFlush' must "
					"be greater than 0.\n");
			return (1);
		}
		cache_flush_timeout = tmp;
	}
	else if (strcasecmp ("DataDir", key) == 0)
	{
		if (datadir != NULL)