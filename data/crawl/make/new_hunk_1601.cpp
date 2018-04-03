     char *s1, *s2, *s3, *s4, *s5, *s6;
{
  if (makelevel == 0)
    fprintf (stderr, "%s: *** ", program);
  else
    fprintf (stderr, "%s[%u]: *** ", program, makelevel);
  fprintf (stderr, s1, s2, s3, s4, s5, s6);
  fputs (".  Stop.\n", stderr);

