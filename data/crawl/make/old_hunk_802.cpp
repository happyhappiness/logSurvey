      percent = find_percent (name);
      if (percent)
        {
          struct pattern_var *p;

          /* Get a reference for this pattern-specific variable struct.  */
          p = create_pattern_var(name, percent);
          vlist = p->vars;
          fname = p->target;
        }
      else
