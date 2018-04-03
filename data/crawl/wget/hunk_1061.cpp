   return ret;
 }
 
-char *get_remote_charset (void)
+struct iri *
+iri_new (void)
 {
-  return remote;
+  struct iri *i = xmalloc (sizeof (struct iri));
+  i->uri_encoding = opt.encoding_remote ? xstrdup (opt.encoding_remote) : NULL;
+  i->content_encoding = NULL;
+  i->utf8_encode = opt.enable_iri;
 }
 
-char *get_current_charset (void)
-{
-  return current;
-}
-
-void set_current_charset (char *charset)
-{
-  /*printf("[ current = `%s'\n", charset);*/
-  if (current)
-    {
-      /* Do nothing if already equal */
-      if (!strcasecmp (current, charset))
-        return;
-      xfree (current);
-    }
-
-  current = charset ? xstrdup (charset) : NULL;
-}
-
-void set_current_as_locale (void)
+void
+iri_free (struct iri *i)
 {
-  /* sXXXav : assert opt.locale NULL ? */
-  /*printf("[ current = locale = `%s'\n", opt.locale);*/
-  if (current)
-    {
-      if (!strcasecmp (current, opt.locale))
-        return;
-      xfree (current);
-    }
-
-  current = xstrdup (opt.locale);
+  xfree_null (i->uri_encoding);
+  xfree_null (i->content_encoding);
+  xfree (i);
 }
 
 void
-set_remote_charset (char *charset)
+set_uri_encoding (struct iri *i, char *charset)
 {
-  /*printf("[ remote = `%s'\n", charset);*/
-  if (remote)
+  logprintf (LOG_VERBOSE, "[ uri = `%s'\n", charset);
+  if (opt.encoding_remote)
+    return;
+  if (i->uri_encoding)
     {
-      /* Do nothing if already equal */
-      if (!strcasecmp (remote, charset))
+      if (!strcasecmp (i->uri_encoding, charset))
         return;
-      xfree (remote);
+      xfree (i->uri_encoding);
     }
-  remote = charset ? xstrdup (charset) : NULL;
+
+  i->uri_encoding = charset ? xstrdup (charset) : NULL;
 }
 
 void
-set_remote_as_current (void)
+set_content_encoding (struct iri *i, char *charset)
 {
-  /*printf("[ remote = current = `%s'\n", current);*/
-  if (remote)
+  logprintf (LOG_VERBOSE, "[ content = `%s'\n", charset);
+  if (opt.encoding_remote)
+    return;
+  if (i->content_encoding)
     {
-      /* Do nothing if already equal */
-      if (current && !strcasecmp (remote, current))
+      if (!strcasecmp (i->content_encoding, charset))
         return;
-      xfree (remote);
+      xfree (i->content_encoding);
     }
 
-  remote = current ? xstrdup (current) : NULL;
-}
-
-void reset_utf8_encode (void)
-{
-  set_utf8_encode (opt.enable_iri);
-}
-
-void set_utf8_encode (bool encode)
-{
-  utf8_encode = encode;
-}
-
-bool get_utf8_encode (void)
-{
-  return (!ugly_no_encode && utf8_encode);
-}
-
-void set_ugly_no_encode (bool ugly)
-{
-  ugly_no_encode = ugly;
+  i->content_encoding = charset ? xstrdup (charset) : NULL;
 }
 
