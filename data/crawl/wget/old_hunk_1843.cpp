        }
      if (opt.timestamping)
        {
          fputs (_("\
Cannot specify -N if -O is given. See the manual for details.\n\n"), stdout);
          print_usage ();
          exit (1);
        }
    }
