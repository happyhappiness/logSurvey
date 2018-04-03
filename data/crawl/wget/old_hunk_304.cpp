        {
          if (ret == '?')
            {
              print_usage (0);
              printf ("\n");
              printf (_("Try `%s --help' for more options.\n"), exec_name);
              exit (2);
            }
          /* Find the short option character in the mapping.  */
