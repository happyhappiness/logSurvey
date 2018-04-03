
  return (val <= 0 ? (time_t) -1 : (time_t) val);
}

/* Set the archive-member NAME's modtime to now.  */

#ifdef VMS
int
ar_touch (const char *name)
{
  error (NILF, _("touch archive member is not available on VMS"));
  return -1;
}
#else
int
ar_touch (const char *name)
{
  char *arname, *memname;
  int arname_used = 0;
