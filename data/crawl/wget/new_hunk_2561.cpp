  if (!base)
    {
      DEBUGP (("%s: no base, merge will use \"%s\".\n",
               ctx->document_file, link_uri));

      if (!link_has_scheme)
        {
          /* Base URL is unavailable, and the link does not have a
             location attached to it -- we have to give up.  Since
             this can only happen when using `--force-html -i', print
             a warning.  */
          logprintf (LOG_NOTQUIET,
                     _("%s: Cannot resolve incomplete link %s.\n"),
                     ctx->document_file, link_uri);
          return NULL;
        }

      url = url_parse (link_uri, NULL);
      if (!url)
        {
          DEBUGP (("%s: link \"%s\" doesn't parse.\n",
                   ctx->document_file, link_uri));
          return NULL;
        }
    }
  else
    {
      /* Merge BASE with LINK_URI, but also make sure the result is
         canonicalized, i.e. that "../" have been resolved.
         (parse_url will do that for us.) */

      char *complete_uri = uri_merge (base, link_uri);

      DEBUGP (("%s: merge(\"%s\", \"%s\") -> %s\n",
               ctx->document_file, base, link_uri, complete_uri));

      url = url_parse (complete_uri, NULL);
      if (!url)
        {
          DEBUGP (("%s: merged link \"%s\" doesn't parse.\n",
                   ctx->document_file, complete_uri));
          xfree (complete_uri);
          return NULL;
        }
      xfree (complete_uri);
    }

