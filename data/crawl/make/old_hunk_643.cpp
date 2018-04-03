        continue;

      /* Create the dependency list.
         If we're not doing 2nd expansion, then it's just the name.  */
      if (! d->need_2nd_expansion)
        p = d->name;
      else
        {
          /* If it's from a static pattern rule, convert the patterns into
