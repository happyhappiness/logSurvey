 		return (-1);
 	}
 
-	DBG ("rrd_update (%s, %s, %s)", argv[0], argv[1], argv[2]);
+	rc = rrd_cache_insert (filename, values);
+	if (rc == NULL)
+		return (-1);
 
-	optind = 0; /* bug in librrd? */
-	rrd_clear_error ();
-	if (rrd_update (3, argv) == -1)
+	if (cache == NULL)
+	{
+		rrd_write_cache_entry (filename, rc);
+		free (rc->values);
+		free (rc);
+		return (0);
+	}
+
+	now = time (NULL);
+
+	DBG ("age (%s) = %i", filename, now - rc->first_value);
+
+	if ((now - rc->first_value) >= cache_timeout)
+		rrd_write_cache_entry (filename, rc);
+
+	if ((time (NULL) - cache_flush) >= cache_timeout)
+	{
+		rrd_cache_flush (cache_timeout);
+	}
+
+	return (0);
+} /* int rrd_dispatch */
+
+static int rrd_config (const char *key, const char *val)
+{
+	if (strcasecmp ("CacheTimeout", key) == 0)
+	{
+		int tmp = atoi (val);
+		if (tmp < 0)
+		{
+			fprintf (stderr, "rrdtool: `CacheTimeout' must "
+					"be greater than 0.\n");
+			return (1);
+		}
+		cache_timeout = tmp;
+	}
+	else
 	{
-		syslog (LOG_WARNING, "rrd_update failed: %s: %s",
-				filename, rrd_get_error ());
 		return (-1);
 	}
 	return (0);
-} /* int rrd_update_file */
+} /* int rrd_config */
+
+static int rrd_shutdown (void)
+{
+	rrd_cache_flush (-1);
+
+	return (0);
+} /* int rrd_shutdown */
+
+static int rrd_init (void)
+{
+	if (cache_timeout < 2)
+	{
+		cache_timeout = 0;
+	}
+	else
+	{
+		cache = llist_create ();
+		cache_flush = time (NULL);
+		plugin_register_shutdown ("rrdtool", rrd_shutdown);
+	}
+	return (0);
+} /* int rrd_init */
 
 void module_register (void)
 {
+	plugin_register_config ("rrdtool", rrd_config,
+			config_keys, config_keys_num);
+	plugin_register_init ("rrdtool", rrd_init);
 	plugin_register_write ("rrdtool", rrd_write);
 }