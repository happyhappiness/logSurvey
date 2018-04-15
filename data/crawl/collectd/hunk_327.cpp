   if (fh == NULL)
   {
     char errbuf[1024];
-    ERROR ("open (%s) failed: %s", 
+    fprintf (stderr, "Failed to open types database `%s': %s.\n",
+	file, sstrerror (errno, errbuf, sizeof (errbuf)));
+    ERROR ("Failed to open types database `%s': %s",
 	file, sstrerror (errno, errbuf, sizeof (errbuf)));
     return (-1);
   }