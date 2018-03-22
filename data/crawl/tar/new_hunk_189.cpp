  error (TAREXIT_FAILURE, 0, _("Error is not recoverable: exiting now"));
  abort ();
}

void
xalloc_die (void)
{
  error (0, 0, "%s", _("memory exhausted"));
  fatal_exit ();
}
