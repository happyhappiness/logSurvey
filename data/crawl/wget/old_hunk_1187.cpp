  /* No luck with the cache; resolve HOST. */

  if (!silent && !numeric_address)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), escnonprint (host));

#ifdef ENABLE_IPV6
  {
src/ChangeLog   | 4 ++++
src/Makefile.am | 2 +-
2 files changed, 5 insertions(+), 1 deletion(-)
