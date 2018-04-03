	    /* Is there a variable reference inside the parens or braces?
	       If so, expand it before expanding the entire reference.  */

	    end = index (beg, closeparen);
	    if (end == 0)
              /* Unterminated variable reference.  */
              fatal (reading_file, _("unterminated variable reference"));
