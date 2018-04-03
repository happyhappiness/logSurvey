      int option_index;

      for (nameend = nextchar; *nameend && *nameend != '='; nameend++)
        /* Do nothing.  */ ;

      /* Test all long options for either exact match
         or abbreviated matches.  */
      for (p = longopts, option_index = 0; p->name; p++, option_index++)
        if (!strncmp (p->name, nextchar, nameend - nextchar))
          {
            if ((unsigned int) (nameend - nextchar)
                == (unsigned int) strlen (p->name))
              {
                /* Exact match found.  */
                pfound = p;
                indfound = option_index;
                exact = 1;
                break;
              }
            else if (pfound == NULL)
              {
                /* First nonexact match found.  */
                pfound = p;
                indfound = option_index;
              }
            else
              /* Second or later nonexact match found.  */
              ambig = 1;
          }

      if (ambig && !exact)
        {
          if (opterr)
            fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
                     argv[0], argv[optind]);
          nextchar += strlen (nextchar);
          optind++;
          optopt = 0;
          return '?';
        }

      if (pfound != NULL)
        {
          option_index = indfound;
          optind++;
          if (*nameend)
            {
              /* Don't test has_arg with >, because some C compilers don't
                 allow it to be used on enums.  */
              if (pfound->has_arg)
                optarg = nameend + 1;
              else
                {
                  if (opterr)
                    {
                      if (argv[optind - 1][1] == '-')
                        /* --option */
                        fprintf (stderr,
                                 _("%s: option `--%s' doesn't allow an argument\n"),
                                 argv[0], pfound->name);
                      else
                        /* +option or -option */
                        fprintf (stderr,
                                 _("%s: option `%c%s' doesn't allow an argument\n"),
                                 argv[0], argv[optind - 1][0], pfound->name);
                    }

                  nextchar += strlen (nextchar);

                  optopt = pfound->val;
                  return '?';
                }
            }
          else if (pfound->has_arg == 1)
            {
              if (optind < argc)
                optarg = argv[optind++];
              else
                {
                  if (opterr)
                    fprintf (stderr,
                           _("%s: option `%s' requires an argument\n"),
                           argv[0], argv[optind - 1]);
                  nextchar += strlen (nextchar);
                  optopt = pfound->val;
                  return optstring[0] == ':' ? ':' : '?';
                }
            }
          nextchar += strlen (nextchar);
          if (longind != NULL)
            *longind = option_index;
          if (pfound->flag)
            {
              *(pfound->flag) = pfound->val;
              return 0;
            }
          return pfound->val;
        }

      /* Can't find it as a long option.  If this is not getopt_long_only,
         or the option starts with '--' or is not a valid short
         option, then it's an error.
         Otherwise interpret it as a short option.  */
      if (!long_only || argv[optind][1] == '-'
          || my_index (optstring, *nextchar) == NULL)
        {
          if (opterr)
            {
              if (argv[optind][1] == '-')
                /* --option */
                fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
                         argv[0], nextchar);
              else
                /* +option or -option */
                fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
                         argv[0], argv[optind][0], nextchar);
            }
          nextchar = (char *) "";
          optind++;
          optopt = 0;
          return '?';
        }
    }

  /* Look at and handle the next short option-character.  */
