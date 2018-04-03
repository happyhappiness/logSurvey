		/* Look up the value of the variable.  */
		end = index (beg, closeparen);
		if (end == 0)
		  return initialize_variable_output ();
		o = reference_variable (o, beg, end - beg);
	      }

