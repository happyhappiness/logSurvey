static void
ws_hangup (const char *reason)
{
  fprintf (stderr, _("Continuing in background.\n"));
  log_request_redirect_output (reason);

  /* Detach process from the current console.  Under Windows 9x, if we
