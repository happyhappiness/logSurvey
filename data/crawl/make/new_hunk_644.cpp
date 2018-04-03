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
