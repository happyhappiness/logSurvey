  if (!valid_progress_implementation_p (val))
    {
      fprintf (stderr, _("%s: %s: Invalid progress type `%s'.\n"),
               exec_name, com, val);
      return false;
    }
  xfree_null (opt.progress_type);
