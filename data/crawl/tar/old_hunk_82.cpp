  name_term ();

  if (exit_status == TAREXIT_FAILURE)
    error (0, 0, _("Error exit delayed from previous errors"));

  if (stdlis == stdout)
    close_stdout ();
