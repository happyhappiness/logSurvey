     {
       logfp = fopen (file, appendp ? "a" : "w");
       if (!logfp)
-	{
-	  fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
-	  exit (1);
-	}
+        {
+          fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
+          exit (1);
+        }
     }
   else
     {
