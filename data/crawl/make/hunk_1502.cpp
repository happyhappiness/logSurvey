 	    /* Is there a variable reference inside the parens or braces?
 	       If so, expand it before expanding the entire reference.  */
 
-	    p1 = index (beg, closeparen);
+	    end = index (beg, closeparen);
+	    if (end == 0)
+	      {
+		/* Unterminated variable reference.  */
+		if (reading_filename != 0)
+		  makefile_fatal (reading_filename, *reading_lineno_ptr,
+				  "unterminated variable reference");
+		else
+		  fatal ("unterminated variable reference");
+	      }
+	    p1 = lindex (beg, end, '$');
 	    if (p1 != 0)
-	      p1 = lindex (beg, p1, '$');
-	    if (p1 != 0 && lindex (beg, p1, ':') == 0)
 	      {
 		/* BEG now points past the opening paren or brace.
 		   Count parens or braces until it is matched.  */
