void
set_uri_encoding (struct iri *i, char *charset)
{
  DEBUGP (("[IRI uri = `%s'\n", quote (charset)));
  if (opt.encoding_remote)
    return;
  if (i->uri_encoding)
