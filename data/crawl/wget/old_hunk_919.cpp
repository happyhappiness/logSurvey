void
set_content_encoding (struct iri *i, char *charset)
{
  logprintf (LOG_VERBOSE, "[ content = `%s'\n", charset);
  if (opt.encoding_remote)
    return;
  if (i->content_encoding)
