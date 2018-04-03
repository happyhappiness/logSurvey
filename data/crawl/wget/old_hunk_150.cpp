      opt.always_rest = false;
    }

  if (!nurl && !opt.input_filename)
    {
      /* No URL specified.  */
      fprintf (stderr, _("%s: missing URL\n"), exec_name);
