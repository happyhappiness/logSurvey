     junk to the server.  */
  if (!*val || strchr (val, '\n'))
    {
      fprintf (stderr, _("%s: %s: Invalid specification `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
