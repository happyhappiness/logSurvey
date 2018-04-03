  /* No luck with the cache; resolve HOST. */

  if (!silent && !numeric_address)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), escnonprint (host));

#ifdef ENABLE_IPV6
  {
src/http.c | 15 +++++++++------
1 file changed, 9 insertions(+), 6 deletions(-)
