	p3 = find_percent (p);
	if (!p3)
	  {
	    /* Give a warning if there is no pattern.  */
	    error (NILF, _(".LIBPATTERNS element `%s' is not a pattern"), p);
            p[len] = c;
	    continue;
	  }
	p4 = variable_buffer_output (libbuf, p, p3-p);
	p4 = variable_buffer_output (p4, lib, liblen);
	p4 = variable_buffer_output (p4, p3+1, len - (p3-p));
	p[len] = c;
      }
