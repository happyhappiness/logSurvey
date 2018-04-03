  /* No luck with the cache; resolve HOST. */

  if (!silent && !numeric_address)
    logprintf (LOG_VERBOSE, _("Resolving %s... "), 
               quotearg_style (escape_quoting_style, host));

#ifdef ENABLE_IPV6
  {
src/http.c | 15 +++++++++------
1 file changed, 9 insertions(+), 6 deletions(-)
