load_file (const gmk_floc *flocp, const char **ldname, int noerror)
{
  if (! noerror)
    O (fatal, flocp,
       _("The 'load' operation is not supported on this platform."));

  return 0;
}
