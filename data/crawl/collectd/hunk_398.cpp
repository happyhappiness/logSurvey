 		{
 			fprintf (stderr, "rrdtool: `CacheTimeout' must "
 					"be greater than 0.\n");
+			ERROR ("rrdtool: `CacheTimeout' must "
+					"be greater than 0.\n");
 			return (1);
 		}
 		cache_timeout = tmp;
