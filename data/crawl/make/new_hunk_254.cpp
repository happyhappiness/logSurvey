         'targets: target%pattern: prereq%pattern; recipe',
         make sure the pattern matches this target name.  */
      if (pattern && !pattern_matches (pattern, pattern_percent, name))
        OS (error, flocp,
            _("target '%s' doesn't match the target pattern"), name);
      else if (deps)
        /* If there are multiple targets, copy the chain DEPS for all but the
           last one.  It is not safe for the same deps to go in more than one
