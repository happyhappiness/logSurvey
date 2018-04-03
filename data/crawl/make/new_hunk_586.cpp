      cmds->command_lines = 0;
    }
  else
     cmds = 0;

  /* If there's a prereq string then parse it--unless it's eligible for 2nd
     expansion: if so, snap_deps() will do it.  */
  if (depstr == 0)
    deps = 0;
  else if (second_expansion && strchr (depstr, '$'))
    {
      deps = alloc_dep ();
      deps->name = depstr;
      deps->need_2nd_expansion = 1;
      deps->staticpattern = pattern != 0;
    }
  else
    {
      deps = split_prereqs (depstr);
      free (depstr);

      /* We'll enter static pattern prereqs later when we have the stem.  We
         don't want to enter pattern rules at all so that we don't think that
         they ought to exist (make manual "Implicit Rule Search Algorithm",
         item 5c).  */
      if (! pattern && ! implicit_percent)
        deps = enter_prereqs (deps, NULL);
    }

  /* For implicit rules, _all_ the targets must have a pattern.  That means we
     can test the first one to see if we're working with an implicit rule; if
     so we handle it specially. */

  if (implicit_percent)
    {
      struct nameseq *nextf;
      const char **targets, **target_pats;
      unsigned int c;

      if (pattern != 0)
        fatal (flocp, _("mixed implicit and static pattern rules"));

      /* Create an array of target names */
      for (c = 1, nextf = filenames->next; nextf; ++c, nextf = nextf->next)
        ;
      targets = xmalloc (c * sizeof (const char *));
      target_pats = xmalloc (c * sizeof (const char *));

      targets[0] = name;
      target_pats[0] = implicit_percent;

      for (c = 1, nextf = filenames->next; nextf; ++c, nextf = nextf->next)
        {
          name = nextf->name;
          implicit_percent = find_percent_cached (&name);

          if (implicit_percent == 0)
            fatal (flocp, _("mixed implicit and normal rules"));

	  targets[c] = name;
	  target_pats[c] = implicit_percent;
        }

      create_pattern_rule (targets, target_pats, c, two_colon, deps, cmds, 1);

      return;
    }


  /* Walk through each target and create it in the database.
     We already set up the first target, above.  */
  while (1)
    {
      struct nameseq *nextf = filenames->next;
      struct file *f;
      struct dep *this = 0;

      free (filenames);

      /* Check for special targets.  Do it here instead of, say, snap_deps()
         so that we can immediately use the value.  */
      if (streq (name, ".POSIX"))
        posix_pedantic = 1;
      else if (streq (name, ".SECONDEXPANSION"))
        second_expansion = 1;

      /* If this is a static pattern rule:
         `targets: target%pattern: prereq%pattern; recipe',
         make sure the pattern matches this target name.  */
      if (pattern && !pattern_matches (pattern, pattern_percent, name))
        error (flocp, _("target `%s' doesn't match the target pattern"), name);
      else if (deps)
        /* If there are multiple targets, copy the chain DEPS for all but the
           last one.  It is not safe for the same deps to go in more than one
           place in the database.  */
        this = nextf != 0 ? copy_dep_chain (deps) : deps;

      /* Find or create an entry in the file database for this target.  */
      if (!two_colon)
	{
	  /* Single-colon.  Combine this rule with the file's existing record,
	     if any.  */
	  f = enter_file (strcache_add (name));
	  if (f->double_colon)
	    fatal (flocp,
                   _("target file `%s' has both : and :: entries"), f->name);
