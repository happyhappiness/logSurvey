                  setoptval ("noparent", "1", opt->long_name);
                  break;
                default:
                  fprintf (stderr, _("%s: illegal option -- `-n%c'\n"),
                           exec_name, *p);
                  print_usage (1);
                  fprintf (stderr, "\n");
                  fprintf (stderr, _("Try `%s --help' for more options.\n"),
                           exec_name);
                  exit (1);
                }
            break;
