
                      if (i < 1 || cp[0] != '\0')
                        {
                          error (NILF, 0,
                                 _("the '-%c' option requires a positive integer argument"),
                                 cs->c);
                          bad = 1;
                        }
