                    if (ns->next != 0)
                      fatal (NILF, _(".DEFAULT_GOAL contains more than one target"));

                    default_goal_file = enter_file (strcache_add (ns->name));

                    ns->name = 0; /* It was reused by enter_file(). */
                    free_ns_chain (ns);
