      i = strlen (text);
      if (sindex (p, 0, text, i) != 0)
	o = variable_buffer_output (o, text, i);
      
      free (p);
      free (text);
      break;
      
    case function_addsuffix:
    case function_addprefix:
      /* Get two comma-separated arguments and expand each one.  */
