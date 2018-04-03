		      ++count;
		    else if (*p == closeparen && --count < 0)
		      break;
		  }
		/* If COUNT is >= 0, there were unmatched opening parens
		   or braces, so we go to the simple case of a variable name
		   such as `$($(a)'.  */
		if (count < 0)
		  {
		    char *name = expand_argument (beg, p);
		    static char start[3] = { '$', }, end[2];
		    start[1] = openparen;
		    end[0] = closeparen;
		    p1 = concat (start, name, end);
		    free (name);
		    name = allocated_variable_expand (p1);
		    o = variable_buffer_output (o, name, strlen (name));
		    free (name);
		    break;
		  }
	      }

