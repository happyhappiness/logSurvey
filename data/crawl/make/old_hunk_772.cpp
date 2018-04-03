	/* This line has been dealt with.  */
	goto rule_complete;

      if (line[0] == '\t')
	{
	  p = collapsed;	/* Ignore comments, etc.  */
	  while (isblank ((unsigned char)*p))
	    ++p;
	  if (*p == '\0')
	    /* The line is completely blank; that is harmless.  */
	    continue;

	  /* This line starts with a tab but was not caught above
	     because there was no preceding target, and the line
	     might have been usable as a variable definition.
	     But now we know it is definitely lossage.  */
	  fatal(fstart, _("commands commence before first target"));
	}

      /* This line describes some target files.  This is complicated by
         the existence of target-specific variables, because we can't
