         plain prerequisite names.  */
      if (new && d->staticpattern)
        {
          char *pattern = "%";
          char *buffer = variable_expand ("");
          struct dep *dp = new, *dl = 0;

          while (dp != 0)
            {
              char *percent = find_percent (dp->name);
              if (percent)
                {
                  /* We have to handle empty stems specially, because that
                     would be equivalent to $(patsubst %,dp->name,) which
                     will always be empty.  */
                  if (d->stem[0] == '\0')
                    /* This needs memmove() in ISO C.  */
                    memmove (percent, percent+1, strlen (percent));
                  else
                    {
                      char *o = patsubst_expand (buffer, d->stem, pattern,
                                                 dp->name, pattern+1,
                                                 percent+1);
                      if (o == buffer)
                        dp->name[0] = '\0';
                      else
                        {
                          free (dp->name);
                          dp->name = savestring (buffer, o - buffer);
                        }
                    }

                  /* If the name expanded to the empty string, ignore it.  */
                  if (dp->name[0] == '\0')
                    {
                      struct dep *df = dp;
                      if (dp == new)
                        dp = new = new->next;
                      else
                        dp = dl->next = dp->next;
                      /* @@ Are we leaking df->name here?  */
                      df->name = 0;
                      free_dep (df);
                      continue;
                    }
                }
              dl = dp;
              dp = dp->next;
