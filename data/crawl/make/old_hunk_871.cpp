
void
pfatal_with_name (name)
     char *name;
{
  fatal (NILF, "%s: %s", name, strerror (errno));

