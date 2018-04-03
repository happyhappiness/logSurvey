	return (0);
} /* int rrd_write */

static int rrd_config (const char *key, const char *val)
{
	if (strcasecmp ("CacheTimeout", key) == 0)
	{
		int tmp = atoi (val);
		if (tmp < 0)
		{
			fprintf (stderr, "rrdtool: `CacheTimeout' must "
