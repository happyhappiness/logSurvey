     int entering;
{
  static int entered = 0;
  char *msg = entering ? _("Entering") : _("Leaving");

  /* Print nothing without the flag.  Don't print the entering message
     again if we already have.  Don't print the leaving message if we
