	    }
	  else if (!ignoring
		   && !try_variable_definition (&fileinfo, p2, o_override))
	    error (&fileinfo, "invalid `override' directive");

	  continue;
	}
