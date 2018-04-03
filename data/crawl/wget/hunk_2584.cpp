   if (stat (file, &sb))
     {
       fprintf (stderr, _("%s: cannot stat %s: %s\n"), argv[0], file,
-	       strerror (errno));
+               strerror (errno));
       exit (1);
     }
 
