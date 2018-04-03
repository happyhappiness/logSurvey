      if (opt.noclobber && file_exists_p(opt.output_document))
           {
              /* Check if output file exists; if it does, exit. */
              logprintf (LOG_VERBOSE, _("File `%s' already there; not retrieving.\n"), opt.output_document);
              exit(1);
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
      printf (_("%s: missing URL\n"), exec_name);
      print_usage ();
      printf ("\n");
      /* #### Something nicer should be printed here -- similar to the
         pre-1.5 `--help' page.  */
      printf (_("Try `%s --help' for more options.\n"), exec_name);
      exit (1);
    }

