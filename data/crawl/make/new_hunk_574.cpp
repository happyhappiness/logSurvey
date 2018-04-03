		    optarg = xstrdup (cs->noarg_value);
                  else if (*optarg == '\0')
                    {
                      char opt[2] = "c";
                      const char *op = opt;

                      if (short_option (cs->c))
                        opt[0] = cs->c;
                      else
                        op = cs->long_name;

                      error (NILF, _("the `%s%s' option requires a non-empty string argument"),
                             short_option (cs->c) ? "-" : "--", op);
                      bad = 1;
                    }

