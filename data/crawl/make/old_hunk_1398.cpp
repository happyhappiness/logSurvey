fatal_error_signal (sig)
     int sig;
{
#if defined(__MSDOS__) || defined(_AMIGA)
  remove_intermediates (1);
#ifdef _AMIGA
  if (sig == SIGINT)
     fputs ("*** Break.\n", stderr);

  exit (10);
#else
  exit (1);
#endif
#else	/* Not MSDOS.  */
  handling_fatal_signal = 1;

  /* Set the handling for this signal to the default.
