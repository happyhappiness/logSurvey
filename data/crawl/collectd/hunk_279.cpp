 
   assert (strcasecmp (argv[0], "flush") == 0);
 
-  connection = NULL;
-  status = lcc_connect (address, &connection);
-  if (status != 0) {
-    fprintf (stderr, "ERROR: Failed to connect to daemon at %s: %s.\n",
-        address, strerror (errno));
-    return (1);
-  }
-
   for (i = 1; i < argc; ++i) {
     char *key, *value;
 
