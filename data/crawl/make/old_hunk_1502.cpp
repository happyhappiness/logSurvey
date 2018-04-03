	    /* Is there a variable reference inside the parens or braces?
	       If so, expand it before expanding the entire reference.  */

	    p1 = index (beg, closeparen);
	    if (p1 != 0)
	      p1 = lindex (beg, p1, '$');
	    if (p1 != 0 && lindex (beg, p1, ':') == 0)
	      {
		/* BEG now points past the opening paren or brace.
		   Count parens or braces until it is matched.  */
