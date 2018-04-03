 
 	    end = index (beg, closeparen);
 	    if (end == 0)
-	      {
-		/* Unterminated variable reference.  */
-		if (reading_filename != 0)
-		  makefile_fatal (reading_filename, *reading_lineno_ptr,
-				  "unterminated variable reference");
-		else
-		  fatal ("unterminated variable reference");
-	      }
+              /* Unterminated variable reference.  */
+              fatal (reading_file, "unterminated variable reference");
 	    p1 = lindex (beg, end, '$');
 	    if (p1 != 0)
 	      {
