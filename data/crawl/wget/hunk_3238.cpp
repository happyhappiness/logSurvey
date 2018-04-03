       logfp = fopen (file, appendp ? "a" : "w");
       if (!logfp)
 	{
-	  perror (opt.lfilename);
+	  fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
 	  exit (1);
 	}
     }
