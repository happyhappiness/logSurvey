
      /* Parse the line.  */
      status = parse_line (line, &com, &val);
      free (line);
      /* If everything is OK, set the value.  */
      if (status == 1)
	{
	  if (!setval (com, val))
	    fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
		     file, ln);
	  free (com);
	  free (val);
	}
      else if (status == 0)
	fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
