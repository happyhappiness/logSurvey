  if (status)
    {
      fprintf (stderr,
              _("Error initializing spawn file actions for use-askpass: %d\n"),
              status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }
