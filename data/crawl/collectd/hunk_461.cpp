 	 * Change directory. We do this _after_ reading the config and loading
 	 * modules to relative paths work as expected.
 	 */
-	if ((datadir = global_option_get ("BaseDir")) == NULL)
+	if ((basedir = global_option_get ("BaseDir")) == NULL)
 	{
-		fprintf (stderr, "Don't have a datadir to use. This should not happen. Ever.");
+		fprintf (stderr, "Don't have a basedir to use. This should not happen. Ever.");
 		return (1);
 	}
-	else if (change_basedir (datadir))
+	else if (change_basedir (basedir))
 	{
-		fprintf (stderr, "Error: Unable to change to directory `%s'.\n", datadir);
+		fprintf (stderr, "Error: Unable to change to directory `%s'.\n", basedir);
 		return (1);
 	}
 
+	/*
+	 * Set global variables or, if that failes, exit. We cannot run with
+	 * them being uninitialized. If nothing is configured, then defaults
+	 * are being used. So this means that the user has actually done
+	 * something wrong.
+	 */
+	if (init_global_variables () != 0)
+		return (1);
+
 #if COLLECT_DAEMON
 	/*
 	 * fork off child
