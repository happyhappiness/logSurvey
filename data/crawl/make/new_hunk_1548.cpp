		end = index (beg, closeparen);
		if (end == 0)
		  return initialize_variable_output ();
		o = reference_variable (o, beg, end - beg);
	      }

	    /* Advance p past the variable reference to resume scan.  */
