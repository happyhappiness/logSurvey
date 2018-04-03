 	      if (bad)
 		fatal ("Couldn't change back to original directory.");
 	    }
-	  fflush (stdout);
-	  fflush (stderr);
+
 	  for (p = environ; *p != 0; ++p)
 	    if (!strncmp (*p, "MAKELEVEL=", 10))
 	      {
