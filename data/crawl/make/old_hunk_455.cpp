
      /* Find or create an entry in the file database for this target.  */
      if (!two_colon)
	{
	  /* Single-colon.  Combine this rule with the file's existing record,
	     if any.  */
	  f = enter_file (strcache_add (name));
	  if (f->double_colon)
	    fatal (flocp,
                   _("target file '%s' has both : and :: entries"), f->name);

	  /* If CMDS == F->CMDS, this target was listed in this rule
	     more than once.  Just give a warning since this is harmless.  */
	  if (cmds != 0 && cmds == f->cmds)
	    error (flocp,
                   _("target '%s' given more than once in the same rule."),
                   f->name);

	  /* Check for two single-colon entries both with commands.
	     Check is_target so that we don't lose on files such as .c.o
	     whose commands were preinitialized.  */
	  else if (cmds != 0 && f->cmds != 0 && f->is_target)
	    {
	      error (&cmds->fileinfo,
                     _("warning: overriding recipe for target '%s'"),
                     f->name);
	      error (&f->cmds->fileinfo,
                     _("warning: ignoring old recipe for target '%s'"),
                     f->name);
	    }

	  /* Defining .DEFAULT with no deps or cmds clears it.  */
	  if (f == default_file && this == 0 && cmds == 0)
	    f->cmds = 0;
	  if (cmds != 0)
	    f->cmds = cmds;

	  /* Defining .SUFFIXES with no dependencies clears out the list of
	     suffixes.  */
	  if (f == suffix_file && this == 0)
	    {
              free_dep_chain (f->deps);
	      f->deps = 0;
	    }
	}
      else
	{
	  /* Double-colon.  Make a new record even if there already is one.  */
	  f = lookup_file (name);

	  /* Check for both : and :: rules.  Check is_target so we don't lose
	     on default suffix rules or makefiles.  */
	  if (f != 0 && f->is_target && !f->double_colon)
	    fatal (flocp,
                   _("target file '%s' has both : and :: entries"), f->name);

	  f = enter_file (strcache_add (name));
	  /* If there was an existing entry and it was a double-colon entry,
	     enter_file will have returned a new one, making it the prev
	     pointer of the old one, and setting its double_colon pointer to
	     the first one.  */
	  if (f->double_colon == 0)
	    /* This is the first entry for this name, so we must set its
	       double_colon pointer to itself.  */
	    f->double_colon = f;

	  f->cmds = cmds;
	}

      f->is_target = 1;

