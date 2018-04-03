      cmds->command_lines = 0;
    }
  else
    cmds = 0;

  for (; filenames != 0; filenames = nextf)
    {
      const char *name = filenames->name;
      struct file *f;
      struct dep *this = 0;
      const char *implicit_percent;

      nextf = filenames->next;
      free (filenames);

      /* Check for special targets.  Do it here instead of, say, snap_deps()
         so that we can immediately use the value.  */

      if (streq (name, ".POSIX"))
        posix_pedantic = 1;
      else if (streq (name, ".SECONDEXPANSION"))
        second_expansion = 1;

      implicit_percent = find_percent_cached (&name);
      implicit |= implicit_percent != 0;

      if (implicit)
        {
          if (pattern != 0)
            fatal (flocp, _("mixed implicit and static pattern rules"));

          if (implicit_percent == 0)
            fatal (flocp, _("mixed implicit and normal rules"));

	  if (targets == 0)
	    {
	      max_targets = 5;
	      targets = xmalloc (5 * sizeof (char *));
	      target_percents = xmalloc (5 * sizeof (char *));
	      target_idx = 0;
	    }
	  else if (target_idx == max_targets - 1)
	    {
	      max_targets += 5;
	      targets = xrealloc (targets, max_targets * sizeof (char *));
	      target_percents = xrealloc (target_percents,
                                          max_targets * sizeof (char *));
	    }
	  targets[target_idx] = name;
	  target_percents[target_idx] = implicit_percent;
	  ++target_idx;
	  continue;
	}

      /* If this is a static pattern rule:
         `targets: target%pattern: dep%pattern; cmds',
         make sure the pattern matches this target name.  */
      if (pattern && !pattern_matches (pattern, pattern_percent, name))
        error (flocp, _("target `%s' doesn't match the target pattern"), name);
      else if (deps)
        {
          /* If there are multiple filenames, copy the chain DEPS for all but
             the last one.  It is not safe for the same deps to go in more
             than one place in the database.  */
          this = nextf != 0 ? copy_dep_chain (deps) : deps;
          this->need_2nd_expansion = (second_expansion
				      && strchr (this->name, '$'));
        }

      if (!two_colon)
	{
	  /* Single-colon.  Combine these dependencies
	     with others in file's existing record, if any.  */
	  f = enter_file (strcache_add (name));

	  if (f->double_colon)
	    fatal (flocp,
                   _("target file `%s' has both : and :: entries"), f->name);
