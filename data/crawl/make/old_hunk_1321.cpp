	if (!pattern_matches (pattern, pattern_percent, name))
	  {
	    /* Give a warning if the rule is meaningless.  */
	    makefile_error (filename, lineno,
			    "target `%s' doesn't match the target pattern",
			    name);
	    this = 0;
