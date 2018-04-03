  return ret;
}

struct iri *
iri_new (void)
{
  struct iri *i = xmalloc (sizeof (struct iri));
  i->uri_encoding = opt.encoding_remote ? xstrdup (opt.encoding_remote) : NULL;
  i->content_encoding = NULL;
  i->utf8_encode = opt.enable_iri;
}

void
iri_free (struct iri *i)
{
  xfree_null (i->uri_encoding);
  xfree_null (i->content_encoding);
  xfree (i);
}

void
set_uri_encoding (struct iri *i, char *charset)
{
  logprintf (LOG_VERBOSE, "[ uri = `%s'\n", charset);
  if (opt.encoding_remote)
    return;
  if (i->uri_encoding)
    {
      if (!strcasecmp (i->uri_encoding, charset))
        return;
      xfree (i->uri_encoding);
    }

  i->uri_encoding = charset ? xstrdup (charset) : NULL;
}

void
set_content_encoding (struct iri *i, char *charset)
{
  logprintf (LOG_VERBOSE, "[ content = `%s'\n", charset);
  if (opt.encoding_remote)
    return;
  if (i->content_encoding)
    {
      if (!strcasecmp (i->content_encoding, charset))
        return;
      xfree (i->content_encoding);
    }

  i->content_encoding = charset ? xstrdup (charset) : NULL;
}

