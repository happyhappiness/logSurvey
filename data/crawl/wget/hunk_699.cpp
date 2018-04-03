 const char *
 locale_to_utf8 (const char *str)
 {
+  iconv_t l2u;
   char *new;
 
-  if (!strcasecmp (opt.locale, "utf-8"))
-    return str;
+  /* That shouldn't happen, just in case */
+  if (!opt.locale)
+    {
+      logprintf (LOG_VERBOSE, "open_locale_to_utf8: locale is unset\n");
+      opt.locale = find_locale ();
+    }
 
-  if (!open_locale_to_utf8 ())
+  if (!opt.locale || !strcasecmp (opt.locale, "utf-8"))
     return str;
 
-  if (do_conversion (locale2utf8, (char *) str, strlen ((char *) str), &new))
+  l2u = iconv_open ("UTF-8", opt.locale);
+  if (l2u != (iconv_t)(-1))
+    { 
+      logprintf (LOG_VERBOSE, "Conversion from %s to %s isn't supported\n",
+                 quote (opt.locale), quote ("UTF-8"));
+      return str;
+    }
+
+  if (do_conversion (l2u, (char *) str, strlen ((char *) str), &new))
     return (const char *) new;
 
   return str;
 }
 
 /* Do the conversion according to the passed conversion descriptor cd. *out
-   will containes the transcoded string on success. *out content is
+   will contain the transcoded string on success. *out content is
    unspecified otherwise. */
 static bool
 do_conversion (iconv_t cd, char *in, size_t inlen, char **out)
