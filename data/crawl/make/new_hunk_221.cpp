                      else
                        op = cs->long_name;

                      error (NILF, strlen (op),
                             _("the '%s%s' option requires a non-empty string argument"),
                             short_option (cs->c) ? "-" : "--", op);
                      bad = 1;
                    }
