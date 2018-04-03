   return true;
 }
 
-/* Try converting string str from locale to UTF-8. Return a new string
-   on success, or str on error or if conversion isn't needed. */
-const char *
-locale_to_utf8 (const char *str)
-{
-  iconv_t l2u;
-  char *new;
-
-  /* That shouldn't happen, just in case */
-  if (!opt.locale)
-    {
-      logprintf (LOG_VERBOSE, _("locale_to_utf8: locale is unset\n"));
-      opt.locale = find_locale ();
-    }
-
-  if (!opt.locale || !strcasecmp (opt.locale, "utf-8"))
-    return str;
-
-  l2u = iconv_open ("UTF-8", opt.locale);
-  if (l2u == (iconv_t)(-1))
-    {
-      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
-                 quote (opt.locale), quote ("UTF-8"));
-      return str;
-    }
-
-  if (do_conversion (l2u, (char *) str, strlen ((char *) str), &new))
-    return (const char *) new;
-
-  return str;
-}
-
 /* Do the conversion according to the passed conversion descriptor cd. *out
    will contain the transcoded string on success. *out content is
    unspecified otherwise. */
 static bool
-do_conversion (iconv_t cd, char *in, size_t inlen, char **out)
+do_conversion (const char *tocode, const char *fromcode, char *in, size_t inlen, char **out)
 {
+  iconv_t cd;
   /* sXXXav : hummm hard to guess... */
-  size_t len, done, outlen = inlen * 2;
+  size_t len, done, outlen;
   int invalid = 0, tooshort = 0;
-  char *s;
+  char *s, *in_org, *in_save;
 
-  s = xmalloc (outlen + 1);
-  *out = s;
-  len = outlen;
+  cd = iconv_open (tocode, fromcode);
+  if (cd == (iconv_t)(-1))
+    {
+      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
+                 quote (opt.locale), quote ("UTF-8"));
+      return false;
+    }
+
+  /* iconv() has to work on an unescaped string */
+  in_org = in;
+  in_save = in = strndup(in, inlen);
+  url_unescape(in);
+  inlen = strlen(in);
+
+  len = outlen = inlen * 2;
+  *out = s = xmalloc (outlen + 1);
   done = 0;
 
   for (;;)
