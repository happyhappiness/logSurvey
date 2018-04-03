 	}
 	else if (strcasecmp ("CacheFlush", key) == 0)
 	{
-		int tmp = atoi (val);
+		int tmp = atoi (value);
 		if (tmp < 0)
 		{
 			fprintf (stderr, "rrdtool: `CacheFlush' must "
