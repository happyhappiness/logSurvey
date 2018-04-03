                  }
                else
                  /* This makefile was not found at all.  */
                  if (! (d->flags & RM_DONTCARE))
                    {
                      const char *dnm = dep_name (d);
                      size_t l = strlen (dnm);

                      /* This is a makefile we care about.  See how much.  */
                      if (d->flags & RM_INCLUDED)
                        /* An included makefile.  We don't need to die, but we
                           do want to complain.  */
                        error (NILF, l,
