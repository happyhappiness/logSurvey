     *dt &= ~TEXTCSS;
 }
 
+#ifdef HAVE_METALINK
+
+/*
+  Find value of given key. This is intended for Link header, but will
+  work with any header that uses ';' as field separator and '=' as key-value
+  separator.
+
+  Link           = "Link" ":" #link-value
+  link-value     = "<" URI-Reference ">" *( ";" link-param )
+  link-param     = ( ( "rel" "=" relation-types )
+                 | ( "anchor" "=" <"> URI-Reference <"> )
+                 | ( "rev" "=" relation-types )
+                 | ( "hreflang" "=" Language-Tag )
+                 | ( "media" "=" ( MediaDesc | ( <"> MediaDesc <"> ) ) )
+                 | ( "title" "=" quoted-string )
+                 | ( "title*" "=" ext-value )
+                 | ( "type" "=" ( media-type | quoted-mt ) )
+                 | ( link-extension ) )
+  link-extension = ( parmname [ "=" ( ptoken | quoted-string ) ] )
+                 | ( ext-name-star "=" ext-value )
+  ext-name-star  = parmname "*" ; reserved for RFC2231-profiled
+                                ; extensions.  Whitespace NOT
+                                ; allowed in between.
+  ptoken         = 1*ptokenchar
+  ptokenchar     = "!" | "#" | "$" | "%" | "&" | "'" | "("
+                 | ")" | "*" | "+" | "-" | "." | "/" | DIGIT
+                 | ":" | "<" | "=" | ">" | "?" | "@" | ALPHA
+                 | "[" | "]" | "^" | "_" | "`" | "{" | "|"
+                 | "}" | "~"
+  media-type     = type-name "/" subtype-name
+  quoted-mt      = <"> media-type <">
+  relation-types = relation-type
+                 | <"> relation-type *( 1*SP relation-type ) <">
+  relation-type  = reg-rel-type | ext-rel-type
+  reg-rel-type   = LOALPHA *( LOALPHA | DIGIT | "." | "-" )
+  ext-rel-type   = URI
+
+ See more: rfc5988
+*/
+static bool
+find_key_value (const char *start, const char *end, const char *key, char **value)
+{
+  const char *eq;
+  size_t key_len = strlen (key);
+  const char *val_beg, *val_end;
+  const char *key_beg;
+
+  key_beg = start;
+
+  while (key_beg + key_len + 1 < end)
+    {
+      /* Skip whitespaces.  */
+      while (key_beg + key_len + 1 < end && c_isspace (*key_beg))
+        key_beg++;
+      if (strncmp (key_beg, key, key_len))
+        {
+          /* Find next token.  */
+          while (key_beg + key_len + 1 < end && *key_beg != ';')
+            key_beg++;
+          key_beg++;
+          continue;
+        }
+      else
+        {
+          /* Find equals sign.  */
+          eq = key_beg + key_len;
+          while (eq < end && c_isspace (*eq))
+            eq++;
+          if (eq == end)
+            return false;
+          if (*eq != '=')
+            {
+              key_beg++;
+              continue;
+            }
+
+          val_beg = eq + 1;
+          while (val_beg < end && c_isspace (*val_beg))
+            val_beg++;
+          if (val_beg == end)
+            return false;
+          val_end = val_beg + 1;
+          while (val_end < end && *val_end != ';' && !c_isspace (*val_end))
+            val_end++;
+          *value = xstrndup (val_beg, val_end - val_beg);
+          return true;
+        }
+    }
+  *value = NULL;
+  return false;
+}
+
+/* This is to check if given token exists in HTTP header. Tokens are
+   separated by ';'. */
+static bool
+has_key (const char *start, const char *end, const char *key)
+{
+  const char *pos; /* Here would the token start.  */
+  size_t key_len = strlen (key);
+
+  pos = start;
+  while (pos + key_len <= end)
+    {
+      /* Skip whitespaces at beginning.  */
+      while (pos + key_len <= end && c_isspace (*pos))
+        pos++;
+
+      /* Does the prefix of pos match our key?  */
+      if (strncmp (key, pos, key_len))
+        {
+          /* This was not a match.
+             Skip all characters until beginning of next token.  */
+          while (pos + key_len <= end && *pos != ';')
+            pos++;
+          pos++;
+          continue;
+        }
+
+      /* key is prefix of pos. Is it the exact token or just a prefix?  */
+      pos += key_len;
+      while (pos < end && c_isspace (*pos))
+        pos++;
+      if (pos == end || *pos == ';')
+        return true;
+
+      /* This was not a match (just a prefix).
+         Skip all characters until beginning of next token.  */
+      while (pos + key_len <= end && *pos != ';')
+        pos++;
+      pos++;
+    }
+  return false;
+}
+
+/* Find all key=value pairs delimited with ';' or ','. This is intended for
+   Digest header parsing.
+   The usage is:
+
+   const char *pos;
+   for (pos = header_beg; pos = find_key_values (pos, header_end, &key, &val); pos++)
+   {
+     ...
+   }
+
+ */
+static const char *
+find_key_values (const char *start, const char *end, char **key, char **value)
+{
+  const char *key_start, *key_end;
+  const char *eq;
+  const char *val_start, *val_end;
+
+  eq = start;
+  while (eq < end && *eq != '=')
+    {
+      /* Skip tokens without =value part.  */
+      if (*eq == ';' || *eq == ',')
+        start = eq + 1;
+      eq++;
+    }
+
+  if (eq >= end)
+    return NULL;
+
+  key_start = start;
+  while (key_start < eq && c_isspace (*key_start))
+    key_start++;
+
+  key_end = eq - 1;
+  while (key_end > key_start && c_isspace (*key_end))
+    key_end--;
+  key_end++;
+
+  val_start = eq + 1;
+  while (val_start < end && c_isspace (*val_start))
+    val_start++;
+
+  val_end = val_start;
+
+  while (val_end < end && *val_end != ';' &&
+         *val_end != ',' && !c_isspace (*val_end))
+    val_end++;
+
+  *key = xstrndup (key_start, key_end - key_start);
+  *value = xstrndup (val_start, val_end - val_start);
+
+  /* Skip trailing whitespaces.  */
+  while (val_end < end && c_isspace (*val_end))
+    val_end++;
+
+  return val_end;
+}
+
+/* Will return proper metalink_t structure if enough data was found in
+   http response resp. Otherwise returns NULL.
+   Two exit points: one for success and one for failure.  */
+static metalink_t *
+metalink_from_http (const struct response *resp, const struct http_stat *hs,
+                    const struct url *u)
+{
+  metalink_t *metalink = NULL;
+  metalink_file_t *mfile = xnew0 (metalink_file_t);
+  const char *val_beg, *val_end;
+  int res_count = 0, hash_count = 0, sig_count = 0, i;
+
+  DEBUGP (("Checking for Metalink in HTTP response\n"));
+
+  /* Initialize metalink file for our simple use case.  */
+  if (hs->local_file)
+    mfile->name = xstrdup (hs->local_file);
+  else
+    mfile->name = url_file_name (u, NULL);
+
+  /* Begin with 1-element array (for 0-termination). */
+  mfile->checksums = xnew0 (metalink_checksum_t *);
+  mfile->resources = xnew0 (metalink_resource_t *);
+
+  /* Find all Link headers.  */
+  for (i = 0;
+       (i = resp_header_locate (resp, "Link", i, &val_beg, &val_end)) != -1;
+       i++)
+    {
+      char *rel = NULL, *reltype = NULL;
+      char *urlstr = NULL;
+      const char *url_beg, *url_end, *attrs_beg;
+      size_t url_len;
+
+      /* Sample Metalink Link headers:
+
+           Link: <http://www2.example.com/dir1/dir2/dir3/dir4/dir5/example.ext>;
+           rel=duplicate; pri=1; pref; geo=gb; depth=4
+
+           Link: <http://example.com/example.ext.asc>; rel=describedby;
+           type="application/pgp-signature"
+       */
+
+      /* Find beginning of URL.  */
+      url_beg = val_beg;
+      while (url_beg < val_end - 1 && c_isspace (*url_beg))
+        url_beg++;
+
+      /* Find end of URL.  */
+      /* The convention here is that end ptr points to one element after
+         end of string. In this case, it should be pointing to the '>', which
+         is one element after end of actual URL. Therefore, it should never point
+         to val_end, which is one element after entire header value string.  */
+      url_end = url_beg + 1;
+      while (url_end < val_end - 1 && *url_end != '>')
+        url_end++;
+
+      if (url_beg >= val_end || url_end >= val_end ||
+          *url_beg != '<' || *url_end != '>')
+        {
+          DEBUGP (("This is not a valid Link header. Ignoring.\n"));
+          continue;
+        }
+
+      /* Skip <.  */
+      url_beg++;
+      url_len = url_end - url_beg;
+
+      /* URL found. Now handle the attributes.  */
+      attrs_beg = url_end + 1;
+
+      /* First we need to find out what type of link it is. Currently, we
+         support rel=duplicate and rel=describedby.  */
+      if (!find_key_value (attrs_beg, val_end, "rel", &rel))
+        {
+          DEBUGP (("No rel value in Link header, skipping.\n"));
+          continue;
+        }
+
+      urlstr = xstrndup (url_beg, url_len);
+      DEBUGP (("URL=%s\n", urlstr));
+      DEBUGP (("rel=%s\n", rel));
+
+      /* Handle signatures.
+         Libmetalink only supports one signature per file. Therefore we stop
+         as soon as we successfully get first supported signature.  */
+      if (sig_count == 0 &&
+          !strcmp (rel, "describedby") &&
+          find_key_value (attrs_beg, val_end, "type", &reltype) &&
+          !strcmp (reltype, "application/pgp-signature")
+          )
+        {
+          /* Download the signature to a temporary file.  */
+          FILE *_output_stream = output_stream;
+          bool _output_stream_regular = output_stream_regular;
+
+          output_stream = tmpfile ();
+          if (output_stream)
+            {
+              struct iri *iri = iri_new ();
+              struct url *url;
+              int url_err;
+
+              set_uri_encoding (iri, opt.locale, true);
+              url = url_parse (urlstr, &url_err, iri, false);
+
+              if (!url)
+                {
+                  char *error = url_error (urlstr, url_err);
+                  logprintf (LOG_NOTQUIET, _("When downloading signature:\n"
+                                             "%s: %s.\n"), urlstr, error);
+                  xfree (error);
+                }
+              else
+                {
+                  /* Avoid recursive Metalink from HTTP headers.  */
+                  bool _metalink_http = opt.metalink_over_http;
+                  uerr_t retr_err;
+
+                  opt.metalink_over_http = false;
+                  retr_err = retrieve_url (url, urlstr, NULL, NULL,
+                                           NULL, NULL, false, iri, false);
+                  opt.metalink_over_http = _metalink_http;
+
+                  url_free (url);
+                  iri_free (iri);
+
+                  if (retr_err == RETROK)
+                    {
+                      /* Signature is in the temporary file. Read it into
+                         metalink resource structure.  */
+                      metalink_signature_t msig;
+                      size_t siglen;
+
+                      fseek (output_stream, 0, SEEK_END);
+                      siglen = ftell (output_stream);
+                      fseek (output_stream, 0, SEEK_SET);
+
+                      DEBUGP (("siglen=%lu\n", siglen));
+
+                      msig.signature = xmalloc (siglen + 1);
+                      if (fread (msig.signature, siglen, 1, output_stream) != 1)
+                        {
+                          logputs (LOG_NOTQUIET,
+                                   _("Unable to read signature content from "
+                                     "temporary file. Skipping.\n"));
+                          xfree (msig.signature);
+                        }
+                      else
+                        {
+                          msig.signature[siglen] = '\0'; /* Just in case.  */
+                          msig.mediatype = xstrdup ("application/pgp-signature");
+
+                          DEBUGP (("Signature (%s):\n%s\n",
+                                   msig.mediatype, msig.signature));
+
+                          mfile->signature = xnew (metalink_signature_t);
+                          *mfile->signature = msig;
+
+                          sig_count++;
+                        }
+                    }
+                }
+              fclose (output_stream);
+            }
+          else
+            {
+              logputs (LOG_NOTQUIET, _("Could not create temporary file. "
+                                       "Skipping signature download.\n"));
+            }
+          output_stream_regular = _output_stream_regular;
+          output_stream = _output_stream;
+        } /* Iterate over signatures.  */
+
+        /* Handle Metalink resources.  */
+      else if (!strcmp (rel, "duplicate"))
+        {
+          metalink_resource_t mres = {0};
+          char *pristr;
+
+          /*
+             Valid ranges for the "pri" attribute are from
+             1 to 999999.  Mirror servers with a lower value of the "pri"
+             attribute have a higher priority, while mirrors with an undefined
+             "pri" attribute are considered to have a value of 999999, which is
+             the lowest priority.
+
+             rfc6249 section 3.1
+           */
+          mres.priority = DEFAULT_PRI;
+          if (find_key_value (url_end, val_end, "pri", &pristr))
+            {
+              long pri;
+              char *end_pristr;
+              /* Do not care for errno since 0 is error in this case.  */
+              pri = strtol (pristr, &end_pristr, 10);
+              if (end_pristr != pristr + strlen (pristr) ||
+                  !VALID_PRI_RANGE (pri))
+                {
+                  /* This is against the specification, so let's inform the user.  */
+                  logprintf (LOG_NOTQUIET,
+                             _("Invalid pri value. Assuming %d.\n"),
+                             DEFAULT_PRI);
+                }
+              else
+                mres.priority = pri;
+              xfree (pristr);
+            }
+
+          switch (url_scheme (urlstr))
+            {
+            case SCHEME_HTTP:
+              mres.type = xstrdup ("http");
+              break;
+#ifdef HAVE_SSL
+            case SCHEME_HTTPS:
+              mres.type = xstrdup ("https");
+              break;
+#endif
+            case SCHEME_FTP:
+              mres.type = xstrdup ("ftp");
+              break;
+            default:
+              DEBUGP (("Unsupported url scheme in %s. Skipping resource.\n", urlstr));
+            }
+
+          if (mres.type)
+            {
+              DEBUGP (("TYPE=%s\n", mres.type));
+
+              /* At this point we have validated the new resource.  */
+
+              find_key_value (url_end, val_end, "geo", &mres.location);
+
+              mres.url = urlstr;
+              urlstr = NULL;
+
+              mres.preference = 0;
+              if (has_key (url_end, val_end, "pref"))
+                {
+                  DEBUGP (("This resource has preference\n"));
+                  mres.preference = 1;
+                }
+
+              /* 1 slot from new resource, 1 slot for null-termination.  */
+              mfile->resources = xrealloc (mfile->resources,
+                                           sizeof (metalink_resource_t *) * (res_count + 2));
+              mfile->resources[res_count] = xnew0 (metalink_resource_t);
+              *mfile->resources[res_count] = mres;
+              res_count++;
+            }
+        } /* Handle resource link (rel=duplicate).  */
+      else
+        DEBUGP (("This link header was not used for Metalink\n"));
+
+      xfree (urlstr);
+      xfree (reltype);
+      xfree (rel);
+    } /* Iterate over link headers.  */
+
+  /* Null-terminate resources array.  */
+  mfile->resources[res_count] = 0;
+
+  if (res_count == 0)
+    {
+      DEBUGP (("No valid metalink references found.\n"));
+      goto fail;
+    }
+
+  /* Find all Digest headers.  */
+  for (i = 0;
+       (i = resp_header_locate (resp, "Digest", i, &val_beg, &val_end)) != -1;
+       i++)
+    {
+      const char *dig_pos;
+      char *dig_type, *dig_hash;
+
+      /* Each Digest header can include multiple hashes. Example:
+           Digest: SHA=thvDyvhfIqlvFe+A9MYgxAfm1q5=,unixsum=30637
+           Digest: md5=HUXZLQLMuI/KZ5KDcJPcOA==
+       */
+      for (dig_pos = val_beg;
+           (dig_pos = find_key_values (dig_pos, val_end, &dig_type, &dig_hash));
+           dig_pos++)
+        {
+          /* The hash here is assumed to be base64. We need the hash in hex.
+             Therefore we convert: base64 -> binary -> hex.  */
+          const size_t dig_hash_str_len = strlen (dig_hash);
+          char *bin_hash = alloca (dig_hash_str_len * 3 / 4 + 1);
+          size_t hash_bin_len;
+
+          hash_bin_len = base64_decode (dig_hash, bin_hash);
+
+          /* One slot for me, one for zero-termination.  */
+          mfile->checksums =
+                  xrealloc (mfile->checksums,
+                            sizeof (metalink_checksum_t *) * (hash_count + 2));
+          mfile->checksums[hash_count] = xnew (metalink_checksum_t);
+          mfile->checksums[hash_count]->type = dig_type;
+
+          mfile->checksums[hash_count]->hash = xmalloc (hash_bin_len * 2 + 1);
+          hex_to_string (mfile->checksums[hash_count]->hash, bin_hash, hash_bin_len);
+
+          xfree (dig_hash);
+
+          hash_count++;
+        }
+    }
+
+  /* Zero-terminate checksums array.  */
+  mfile->checksums[hash_count] = 0;
+
+  /*
+    If Instance Digests are not provided by the Metalink servers, the
+    Link header fields pertaining to this specification MUST be ignored.
+
+    rfc6249 section 6
+   */
+  if (hash_count == 0)
+    {
+      logputs (LOG_VERBOSE,
+               _("Could not find acceptable digest for Metalink resources.\n"
+                 "Ignoring them.\n"));
+      goto fail;
+    }
+
+  /* Metalink data is OK. Now we just need to sort the resources based
+     on their priorities, preference, and perhaps location.  */
+  stable_sort (mfile->resources, res_count, sizeof (metalink_resource_t *), metalink_res_cmp);
+
+  /* Restore sensible preference values (in case someone cares to look).  */
+  for (i = 0; i < res_count; ++i)
+    mfile->resources[i]->preference = 1000000 - mfile->resources[i]->priority;
+
+  metalink = xnew0 (metalink_t);
+  metalink->files = xmalloc (sizeof (metalink_file_t *) * 2);
+  metalink->files[0] = mfile;
+  metalink->files[1] = 0;
+  metalink->origin = xstrdup (u->url);
+  metalink->version = METALINK_VERSION_4;
+  /* Leave other fields set to 0.  */
+
+  return metalink;
+
+fail:
+  /* Free all allocated memory.  */
+  if (metalink)
+    metalink_delete (metalink);
+  else
+    metalink_file_delete (mfile);
+  return NULL;
+}
+#endif /* HAVE_METALINK */
+
 /* Retrieve a document through HTTP protocol.  It recognizes status
    code, and correctly handles redirections.  It closes the network
    socket.  If it receives an error from the functions below it, it
