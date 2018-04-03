	/* This line has been dealt with.  */
	goto rule_complete;

      /* This line starts with a tab but was not caught above because there
         was no preceding target, and the line might have been usable as a
         variable definition.  But now we know it is definitely lossage.  */
      if (line[0] == '\t')
        fatal(fstart, _("commands commence before first target"));

      /* This line describes some target files.  This is complicated by
         the existence of target-specific variables, because we can't
