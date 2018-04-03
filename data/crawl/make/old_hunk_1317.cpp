  if (*cmdname == 'e')
    {
      if (*line != '\0')
	makefile_error (filename, lineno,
			"Extraneous text after `%s' directive",
			cmdname);
      /* "Else" or "endif".  */
      if (conditionals->if_cmds == 0)
	makefile_fatal (filename, lineno, "extraneous `%s'", cmdname);
      /* NOTDEF indicates an `endif' command.  */
      if (notdef)
	--conditionals->if_cmds;
      else if (conditionals->seen_else[conditionals->if_cmds - 1])
	makefile_fatal (filename, lineno, "only one `else' per conditional");
      else
	{
	  /* Toggle the state of ignorance.  */
