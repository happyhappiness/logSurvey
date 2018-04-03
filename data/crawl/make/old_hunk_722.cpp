	  continue;
	}

      /* If there are multiple filenames, copy the chain DEPS
	 for all but the last one.  It is not safe for the same deps
	 to go in more than one place in the database.  */
      this = nextf != 0 ? copy_dep_chain (deps) : deps;

      if (pattern != 0)
	{
	  /* If this is an extended static rule:
	     `targets: target%pattern: dep%pattern; cmds',
	     translate each dependency pattern into a plain filename
	     using the target pattern and this target's name.  */
	  if (!pattern_matches (pattern, pattern_percent, name))
	    {
	      /* Give a warning if the rule is meaningless.  */
	      error (flocp,
		     _("target `%s' doesn't match the target pattern"), name);
	      this = 0;
	    }
	  else
            /* We use subst_expand to do the work of translating % to $* in
               the dependency line.  */

            if (this != 0 && find_percent (this->name) != 0)
              {
                char *o;
                char *buffer = variable_expand ("");

                o = subst_expand (buffer, this->name, "%", "$*", 1, 2, 0);

                free (this->name);
                this->name = savestring (buffer, o - buffer);
                this->need_2nd_expansion = 1;
              }
	}

      if (!two_colon)
	{
