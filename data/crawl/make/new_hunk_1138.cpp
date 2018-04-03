
  fprintf (usageto, "Usage: %s [options] [target] ...\n", program);

  fputs (_("Options:\n"), usageto);
  for (cs = switches; cs->c != '\0'; ++cs)
    {
      char buf[1024], shortarg[50], longarg[50], *p;
