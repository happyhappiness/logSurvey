 	if (!pattern_matches (pattern, pattern_percent, name))
 	  {
 	    /* Give a warning if the rule is meaningless.  */
-	    makefile_error (filename, lineno,
+	    error (flocp,
 			    "target `%s' doesn't match the target pattern",
 			    name);
 	    this = 0;
