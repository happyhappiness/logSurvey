 
 	pthread_mutex_lock (&cache_lock);
 
+	DBG ("vc = cache_search (%s)", name);
 	vc = cache_search (name);
 
-	fprintf (fh, "%i", vc->values_num);
-	for (i = 0; i < vc->values_num; i++)
+	if (vc == NULL)
 	{
-		if (vc->gauge[i] == NAN)
-			fprintf (fh, " NaN");
-		else
-			fprintf (fh, " %12e", vc->gauge[i]);
+		DBG ("Did not find cache entry.");
+		fprintf (fh, "-1 No such value");
+	}
+	else
+	{
+		DBG ("Found cache entry.");
+		fprintf (fh, "%i", vc->values_num);
+		for (i = 0; i < vc->values_num; i++)
+		{
+			fprintf (fh, " %s=", vc->ds->ds[i].name);
+			if (vc->gauge[i] == NAN)
+				fprintf (fh, "NaN");
+			else
+				fprintf (fh, "%12e", vc->gauge[i]);
+		}
 	}
 
 	/* Free the mutex as soon as possible and definitely before flushing */
