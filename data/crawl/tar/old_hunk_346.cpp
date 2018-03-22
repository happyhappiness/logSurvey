void
fatal_exit (void)
{
  apply_delayed_set_stat ("");
  error (TAREXIT_FAILURE, 0, _("Error is not recoverable: exiting now"));
  abort ();
}
