                {
                  /* .DEFAULT_GOAL should contain one target. */
                  if (ns->next != 0)
                    fatal (NILF, _(".DEFAULT_GOAL contains more than one target"));

                  f = enter_file (strcache_add (ns->name));

