 		sprintf (*p, "MAKELEVEL=%u", makelevel);
 		break;
 	      }
+
+	  if (debug_flag)
+	    {
+	      char **p;
+	      fputs ("Re-executing:", stdout);
+	      for (p = argv; *p != 0; ++p)
+		printf (" %s", *p);
+	      puts ("");
+	    }
+
+	  fflush (stdout);
+	  fflush (stderr);
+
 	  exec_command (argv, environ);
 	  /* NOTREACHED */
 	}
