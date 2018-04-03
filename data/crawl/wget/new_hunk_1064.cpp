   Return true if robots were retrieved OK, false otherwise.  */

bool
res_retrieve_file (const char *url, char **file, struct iri *iri)
{
  struct iri *i = iri_new ();
  uerr_t err;
  char *robots_url = uri_merge (url, RES_SPECS_LOCATION);
  int saved_ts_val = opt.timestamping;
  int saved_sp_val = opt.spider;

  /* Copy server URI encoding for a possible IDNA transformation, no need to
     encode the full URI in UTF-8 because "robots.txt" is plain ASCII */
  set_uri_encoding (i, iri->uri_encoding);
  i->utf8_encode = false;

  logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
  *file = NULL;
  opt.timestamping = false;
  opt.spider       = false;
  err = retrieve_url (robots_url, file, NULL, NULL, NULL, false, i);
  opt.timestamping = saved_ts_val;
  opt.spider       = saved_sp_val;
  xfree (robots_url);
  iri_free (i);

  if (err != RETROK && *file != NULL)
    {
