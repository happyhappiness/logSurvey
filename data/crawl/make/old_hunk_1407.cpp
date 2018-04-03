	{
	  p = p2 + len;
#ifdef VMS
	  while (p >= p2 && *p != (function == function_notdir ? ']' : '.'))
#else
	  while (p >= p2 && *p != (function == function_notdir ? '/' : '.'))
#endif
	    --p;
	  if (p >= p2)
	    {
	      if (function == function_notdir)
		++p;
	      o = variable_buffer_output (o, p, len - (p - p2));
	    }
	  else if (function == function_notdir)
	    o = variable_buffer_output (o, p2, len);

