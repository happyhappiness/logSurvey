 	if (!pattern_matches (pattern, pattern_percent, name))
 	  {
 	    /* Give a warning if the rule is meaningless.  */
-	    error (flocp,
-			    "target `%s' doesn't match the target pattern",
-			    name);
+	    error (flocp,"target `%s' doesn't match the target pattern", name);
 	    this = 0;
 	  }
 	else
