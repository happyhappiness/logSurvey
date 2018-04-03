      this = nextf != 0 ? copy_dep_chain (deps) : deps;

      if (pattern != 0)
	/* If this is an extended static rule:
	   `targets: target%pattern: dep%pattern; cmds',
	   translate each dependency pattern into a plain filename
	   using the target pattern and this target's name.  */
	if (!pattern_matches (pattern, pattern_percent, name))
	  {
	    /* Give a warning if the rule is meaningless.  */
	    error (flocp,"target `%s' doesn't match the target pattern", name);
	    this = 0;
	  }
	else
	  {
	    /* We use patsubst_expand to do the work of translating
	       the target pattern, the target's name and the dependencies'
	       patterns into plain dependency names.  */
	    char *buffer = variable_expand ("");

	    for (d = this; d != 0; d = d->next)
	      {
		char *o;
		char *percent = find_percent (d->name);
		if (percent == 0)
		  continue;
		o = patsubst_expand (buffer, name, pattern, d->name,
				     pattern_percent, percent);
		free (d->name);
		d->name = savestring (buffer, o - buffer);
	      }
	  }

      if (!two_colon)
	{
