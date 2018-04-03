		end = index (beg, closeparen);
		if (end == 0)
		  return initialize_variable_output ();
		v = lookup_variable (beg, end - beg);

		if (v != 0 && *v->value != '\0')
		  {
		    char *value = (v->recursive ? recursively_expand (v)
				   : v->value);
		    o = variable_buffer_output (o, value, strlen (value));
		    if (v->recursive)
		      free (value);
		  }
	      }

	    /* Advance p past the variable reference to resume scan.  */
