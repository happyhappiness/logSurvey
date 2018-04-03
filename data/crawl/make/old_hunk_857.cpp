	 following lines.  */

      if (!in_ignored_define
	  && (word1eq ("ifdef", 5) || word1eq ("ifndef", 6)
	      || word1eq ("ifeq", 4) || word1eq ("ifneq", 5)
	      || word1eq ("else", 4) || word1eq ("endif", 5)))
	{
	  int i = conditional_line (p, &fileinfo);
	  if (i >= 0)
	    ignoring = i;
	  else
	    fatal (&fileinfo, _("invalid syntax in conditional"));
	  continue;
	}

      if (word1eq ("endef", 5))
	{
	  if (in_ignored_define)
	    in_ignored_define = 0;
	  else
	    fatal (&fileinfo, _("extraneous `endef'"));
	  continue;
	}

      if (word1eq ("define", 6))
	{
	  if (ignoring)
	    in_ignored_define = 1;
	  else
	    {
	      p2 = next_token (p + 6);
              if (*p2 == '\0')
                fatal (&fileinfo, _("empty variable name"));

	      /* Let the variable name be the whole rest of the line,
		 with trailing blanks stripped (comments have already been
