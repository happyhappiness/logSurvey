  if (status)
    {
      fprintf (stderr,
              _("Error setting spawn file actions for use-askpass: %d"),
              status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }

  status = posix_spawnp (&pid, opt.use_askpass, &fa, NULL, argv, environ);
  if (status)
    {
      fprintf (stderr, "Error spawning %s: %d", opt.use_askpass, status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }

