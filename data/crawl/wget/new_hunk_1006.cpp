void
set_content_encoding (struct iri *i, char *charset)
{
  DEBUGP (("[IRI content = %s\n", quote (charset)));
  if (opt.encoding_remote)
    return;
  if (i->content_encoding)
