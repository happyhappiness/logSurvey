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
          this->need_2nd_expansion = second_expansion;
        }

      if (!two_colon)
	{
