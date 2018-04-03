
void
pfatal_with_name (name)
     const char *name;
{
  fatal (NILF, "%s: %s", name, strerror (errno));

