 	  else
 #endif
 	    pid = wait (&status);
-	  fprintf (stderr,"%sblocking wait returned %d\n", block?"":"non",pid);
 
-	  if (pid <= 0)
+	  if (pid < 0)
+	    pfatal_with_name ("wait");
+	  else if (pid == 0)
 	    /* No local children.  */
 	    break;
 	  else
