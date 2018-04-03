 		return (-1);
 
 	value_ptr = (char **) calloc (ds->ds_num, sizeof (char *));
-	/* FIXME: Send some response */
 	if (value_ptr == NULL)
+	{
+		fprintf (fh, "-1 calloc failed.");
 		return (-1);
-
+	}
 
 	{ /* parse the value-list. It's colon-separated. */
 		char *dummy;
