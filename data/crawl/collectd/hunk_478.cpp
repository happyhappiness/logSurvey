 
 	status = format_name (name, sizeof (name),
 			hostname, plugin, plugin_instance, type, type_instance);
-	/* FIXME: Send some response */
 	if (status != 0)
+	{
+		fprintf (fh, "-1 format_name failed.\n");
 		return (-1);
+	}
 
 	pthread_mutex_lock (&cache_lock);
 
