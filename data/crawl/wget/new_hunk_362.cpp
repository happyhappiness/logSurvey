      if (opt.noclobber && file_exists_p(opt.output_document))
           {
              /* Check if output file exists; if it does, exit. */
              logprintf (LOG_VERBOSE,
                         _("File `%s' already there; not retrieving.\n"),
                         opt.output_document);
              exit(1);
           }
    }

  if (opt.ask_passwd && opt.passwd)
    {
      fprintf (stderr,
               _("Cannot specify both --ask-password and --password.\n"));
      print_usage (1);
      exit (1);
    }

  if (!nurl && !opt.input_filename)
    {
      /* No URL specified.  */
      fprintf (stderr, _("%s: missing URL\n"), exec_name);
      print_usage (1);
      printf ("\n");
      /* #### Something nicer should be printed here -- similar to the
         pre-1.5 `--help' page.  */
      fprintf (stderr, _("Try `%s --help' for more options.\n"), exec_name);
      exit (1);
    }

