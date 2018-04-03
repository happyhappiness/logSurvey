
#ifdef VMS
int
ar_touch (char *name)
{
  error (NILF, _("touch archive member is not available on VMS"));
  return -1;
}
#else
int
ar_touch (char *name)
{
  char *arname, *memname;
  int arname_used = 0;
