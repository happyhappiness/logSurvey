	{
	  p = p2 + len;
#ifdef VMS
	  while (p >= p2 && *p != (function == function_dir ? ']' : '.'))
#else
	  while (p >= p2 && *p != (function == function_dir ? '/' : '.'))
#endif
	    --p;
	  if (p >= p2)
	    {
	      if (function == function_dir)
		++p;
	      o = variable_buffer_output (o, p2, p - p2);
	    }
	  else if (function == function_dir)
#ifdef VMS
            o = variable_buffer_output (o, "[]", 2);
