fatal_error_signal (sig)
     int sig;
{
#ifdef	__MSDOS__
  remove_intermediates (1);
  exit (1);
#else	/* Not MSDOS.  */
  handling_fatal_signal = 1;

