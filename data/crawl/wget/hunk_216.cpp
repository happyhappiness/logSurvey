         }
     }
 
+    xfree(in_save);
+    iconv_close(cd);
+    logprintf (LOG_VERBOSE, _("converted '%s' (%s) -> '%s' (%s)\n"), in_org, fromcode, *out, tocode);
     return false;
 }
 
+/* Try converting string str from locale to UTF-8. Return a new string
+   on success, or str on error or if conversion isn't needed. */
+const char *
+locale_to_utf8 (const char *str)
+{
+  char *new;
+
+  /* That shouldn't happen, just in case */
+  if (!opt.locale)
+    {
+      logprintf (LOG_VERBOSE, _("locale_to_utf8: locale is unset\n"));
+      opt.locale = find_locale ();
+    }
+
+  if (!opt.locale || !strcasecmp (opt.locale, "utf-8"))
+    return str;
+
+  if (do_conversion ("UTF-8", opt.locale, (char *) str, strlen ((char *) str), &new))
+    return (const char *) new;
+
+  return str;
+}
+
 /* Try to "ASCII encode" UTF-8 host. Return the new domain on success or NULL
    on error. */
 char *
