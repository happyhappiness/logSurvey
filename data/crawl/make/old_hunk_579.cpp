expand_deps (struct file *f)
{
  struct dep *d;
  struct dep *old = f->deps;
  const char *file_stem = f->stem;
  unsigned int last_dep_has_cmds = f->updating;
  int initialized = 0;

  f->updating = 0;
  f->deps = 0;

  for (d = old; d != 0; d = d->next)
    {
      struct dep *new, *d1;
      char *p;

      if (! d->name)
        continue;

      /* Create the dependency list.
         If we're not doing 2nd expansion, then it's just the name.  We will
         still need to massage it though.  */
      if (! d->need_2nd_expansion)
        {
          p = variable_expand ("");
          variable_buffer_output (p, d->name, strlen (d->name) + 1);
          p = variable_buffer;
        }
      else
        {
          /* If it's from a static pattern rule, convert the patterns into
             "$*" so they'll expand properly.  */
          if (d->staticpattern)
            {
              char *o;
              char *buffer = variable_expand ("");

              o = subst_expand (buffer, d->name, "%", "$*", 1, 2, 0);

              d->name = strcache_add_len (variable_buffer,
                                          o - variable_buffer);
              d->staticpattern = 0; /* Clear staticpattern so that we don't
                                       re-expand %s below. */
            }

          /* We are going to do second expansion so initialize file variables
             for the file. Since the stem for static pattern rules comes from
             individual dep lines, we will temporarily set f->stem to d->stem.
          */
          if (!initialized)
            {
              initialize_file_variables (f, 0);
              initialized = 1;
            }

          if (d->stem != 0)
            f->stem = d->stem;

          set_file_variables (f);

          p = variable_expand_for_file (d->name, f);

          if (d->stem != 0)
            f->stem = file_stem;
        }

      /* Parse the prerequisites.  */
      new = parse_prereqs (p);

      /* If this dep list was from a static pattern rule, expand the %s.  We
         use patsubst_expand to translate the prerequisites' patterns into
         plain prerequisite names.  */
      if (new && d->staticpattern)
        {
          const char *pattern = "%";
          char *buffer = variable_expand ("");
          struct dep *dp = new, *dl = 0;

          while (dp != 0)
            {
              char *percent;
              int nl = strlen (dp->name) + 1;
              char *nm = alloca (nl);
              memcpy (nm, dp->name, nl);
              percent = find_percent (nm);
              if (percent)
                {
                  char *o;

                  /* We have to handle empty stems specially, because that
                     would be equivalent to $(patsubst %,dp->name,) which
                     will always be empty.  */
                  if (d->stem[0] == '\0')
                    {
                      memmove (percent, percent+1, strlen (percent));
                      o = variable_buffer_output (buffer, nm, strlen (nm) + 1);
                    }
                  else
                    o = patsubst_expand_pat (buffer, d->stem, pattern, nm,
                                             pattern+1, percent+1);

                  /* If the name expanded to the empty string, ignore it.  */
                  if (buffer[0] == '\0')
                    {
                      struct dep *df = dp;
                      if (dp == new)
                        dp = new = new->next;
                      else
                        dp = dl->next = dp->next;
                      free_dep (df);
                      continue;
                    }

                  /* Save the name.  */
                  dp->name = strcache_add_len (buffer, o - buffer);
                }
              dl = dp;
              dp = dp->next;
            }
        }

      /* Enter them as files. */
      for (d1 = new; d1 != 0; d1 = d1->next)
        {
          d1->file = lookup_file (d1->name);
          if (d1->file == 0)
            d1->file = enter_file (d1->name);
          d1->name = 0;
          d1->staticpattern = 0;
          d1->need_2nd_expansion = 0;
        }

      /* Add newly parsed deps to f->deps. If this is the last dependency
         line and this target has commands then put it in front so the
         last dependency line (the one with commands) ends up being the
         first. This is important because people expect $< to hold first
         prerequisite from the rule with commands. If it is not the last
         dependency line or the rule does not have commands then link it
         at the end so it appears in makefile order.  */

      if (new != 0)
        {
          if (d->next == 0 && last_dep_has_cmds)
            {
              struct dep **d_ptr;
              for (d_ptr = &new; *d_ptr; d_ptr = &(*d_ptr)->next)
                ;

              *d_ptr = f->deps;
              f->deps = new;
            }
          else
            {
              struct dep **d_ptr;
              for (d_ptr = &f->deps; *d_ptr; d_ptr = &(*d_ptr)->next)
                ;

              *d_ptr = new;
            }
        }
    }

  free_dep_chain (old);
}

/* For each dependency of each file, make the `struct dep' point