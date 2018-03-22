  name_term ();

  if (exit_status == TAREXIT_FAILURE)
    error (0, 0, _("Exiting with failure status due to previous errors"));

  if (stdlis == stdout)
    close_stdout ();
