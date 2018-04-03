void
set_uri_encoding (struct iri *i, char *charset)
{
  logprintf (LOG_VERBOSE, "[ uri = `%s'\n", charset);
  if (opt.encoding_remote)
    return;
  if (i->uri_encoding)
