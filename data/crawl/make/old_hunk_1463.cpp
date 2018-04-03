	      o = variable_buffer_output (o, p2, p - p2);
	    }
	  else if (function == function_dir)
            o = variable_buffer_output (o, "./", 2);
	  else
	    /* The entire name is the basename.  */
	    o = variable_buffer_output (o, p2, len);
