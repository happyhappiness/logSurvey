                        /* An included makefile.  We don't need
                           to die, but we do want to complain.  */
                        error (NILF,
                               _("Included makefile `%s' was not found."),
                               dep_name (d));
                      else
                        {
                          /* A normal makefile.  We must die later.  */
                          error (NILF, _("Makefile `%s' was not found"),
                                 dep_name (d));
                          any_failed = 1;
                        }
