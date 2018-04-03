		/* Look up the value of the variable.  */
		end = index (beg, closeparen);
		if (end == 0)
		  {
		    /* Unterminated variable reference.  */
		    if (reading_filename != 0)
		      makefile_fatal (reading_filename, *reading_lineno_ptr,
				      "unterminated variable reference");
		    else
		      fatal ("unterminated variable reference");
		  }
		o = reference_variable (o, beg, end - beg);
	      }

