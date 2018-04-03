  if (*cmdname == 'e')
    {
      if (*line != '\0')
	error (flocp, _("Extraneous text after `%s' directive"), cmdname);
      /* "Else" or "endif".  */
      if (conditionals->if_cmds == 0)
	fatal (flocp, _("extraneous `%s'"), cmdname);
      /* NOTDEF indicates an `endif' command.  */
      if (notdef)
	--conditionals->if_cmds;
      else if (conditionals->seen_else[conditionals->if_cmds - 1])
	fatal (flocp, _("only one `else' per conditional"));
      else
	{
	  /* Toggle the state of ignorance.  */
