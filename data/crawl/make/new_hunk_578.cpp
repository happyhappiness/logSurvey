  return new;
}

/* Given a list of prerequisites, enter them into the file database.
   If STEM is set then first expand patterns using STEM.  */
struct dep *
enter_prereqs (struct dep *deps, const char *stem)
{
  struct dep *d1;

  if (deps == 0)
    return 0;

  /* If we have a stem, expand the %'s.  We use patsubst_expand to translate
     the prerequisites' patterns into plain prerequisite names.  */
  if (stem)
    {
      const char *pattern = "%";
      char *buffer = variable_expand ("");
      struct dep *dp = deps, *dl = 0;

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
              if (stem[0] == '\0')
                {
                  memmove (percent, percent+1, strlen (percent));
                  o = variable_buffer_output (buffer, nm, strlen (nm) + 1);
                }
              else
                o = patsubst_expand_pat (buffer, stem, pattern, nm,
                                         pattern+1, percent+1);

              /* If the name expanded to the empty string, ignore it.  */
              if (buffer[0] == '\0')
                {
                  struct dep *df = dp;
                  if (dp == deps)
                    dp = deps = deps->next;
                  else
                    dp = dl->next = dp->next;
                  free_dep (df);
                  continue;
                }

              /* Save the name.  */
              dp->name = strcache_add_len (buffer, o - buffer);
            }
          dp->stem = stem;
          dp->staticpattern = 1;
          dl = dp;
          dp = dp->next;
        }
    }

  /* Enter them as files, unless they need a 2nd expansion.  */
  for (d1 = deps; d1 != 0; d1 = d1->next)
    {
      if (d1->need_2nd_expansion)
        continue;

      d1->file = lookup_file (d1->name);
      if (d1->file == 0)
        d1->file = enter_file (d1->name);
      d1->staticpattern = 0;
      d1->name = 0;
    }

  return deps;
}

/* Set the intermediate flag.  */

static void
