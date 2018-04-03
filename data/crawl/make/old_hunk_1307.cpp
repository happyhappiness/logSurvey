		  p = index (p2, '\0');
		  while (isblank (p[-1]))
		    --p;
		  lineno = do_define (p2, p - p2, o_override,
				      lineno, infile, filename);
		}
	    }
	  else if (!ignoring
		   && !try_variable_definition (filename, lineno,
						p2, o_override))
	    makefile_error (filename, lineno, "empty `override' directive");

	  continue;
	}
