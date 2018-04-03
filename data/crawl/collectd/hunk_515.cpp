 	return (0);
 } /* int rrd_write */
 
-static int rrd_config (const char *key, const char *val)
+static int rrd_config (const char *key, const char *value)
 {
 	if (strcasecmp ("CacheTimeout", key) == 0)
 	{
-		int tmp = atoi (val);
+		int tmp = atoi (value);
 		if (tmp < 0)
 		{
 			fprintf (stderr, "rrdtool: `CacheTimeout' must "
