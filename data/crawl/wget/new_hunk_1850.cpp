        }
    }

  if (opt.ask_passwd && opt.passwd)
    {
      printf (_("Cannot specify both --ask-password and --password.\n"));
      print_usage ();
      exit (1);
    }

  if (!nurl && !opt.input_filename)
    {
      /* No URL specified.  */
