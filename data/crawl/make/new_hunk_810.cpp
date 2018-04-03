	p = end_of_token (next_token (t));
      else
	{
	  p = sindex (t, tlen, subst, slen);
	  if (p == 0)
	    {
	      /* No more matches.  Output everything left on the end.  */
	      o = variable_buffer_output (o, t, tlen);
	      return o;
	    }
	}
