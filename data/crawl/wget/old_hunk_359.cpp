                  setoptval ("noparent", "1", opt->long_name);
                  break;
                default:
                  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
                  print_usage ();
                  printf ("\n");
                  printf (_("Try `%s --help' for more options.\n"), exec_name);
                  exit (1);
                }
            break;
