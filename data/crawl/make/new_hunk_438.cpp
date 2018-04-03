#else

int
load_file (const gmk_floc *flocp, const char **ldname, int noerror)
{
  if (! noerror)
    fatal (flocp, _("The 'load' operation is not supported on this platform."));
