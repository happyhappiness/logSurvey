   Return true if robots were retrieved OK, false otherwise.  */

bool
res_retrieve_file (const char *url, char **file)
{
  uerr_t err;
  char *robots_url = uri_merge (url, RES_SPECS_LOCATION);
  int saved_ts_val = opt.timestamping;
  int saved_sp_val = opt.spider;

  logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
  *file = NULL;
  opt.timestamping = false;
  opt.spider       = false;
  err = retrieve_url (robots_url, file, NULL, NULL, NULL, false);
  opt.timestamping = saved_ts_val;
  opt.spider       = saved_sp_val;  
  xfree (robots_url);

  if (err != RETROK && *file != NULL)
    {
