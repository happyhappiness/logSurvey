   return q - (char *) dest;
 }
 
+#ifdef HAVE_LIBPCRE
+/* Compiles the PCRE regex. */
+void *
+compile_pcre_regex (const char *str)
+{
+  const char *errbuf;
+  int erroffset;
+  pcre *regex = pcre_compile (str, 0, &errbuf, &erroffset, 0);
+  if (! regex)
+    {
+      fprintf (stderr, _("Invalid regular expression %s, %s\n"),
+               quote (str), errbuf);
+      return false;
+    }
+  return regex;
+}
+#endif
+
+/* Compiles the POSIX regex. */
+void *
+compile_posix_regex (const char *str)
+{
+  regex_t *regex = xmalloc (sizeof (regex_t));
+  int errcode = regcomp ((regex_t *) regex, str, REG_EXTENDED | REG_NOSUB);
+  if (errcode != 0)
+    {
+      int errbuf_size = regerror (errcode, (regex_t *) regex, NULL, 0);
+      char *errbuf = xmalloc (errbuf_size);
+      errbuf_size = regerror (errcode, (regex_t *) regex, errbuf, errbuf_size);
+      fprintf (stderr, _("Invalid regular expression %s, %s\n"),
+               quote (str), errbuf);
+      xfree (errbuf);
+      return NULL;
+    }
+
+  return regex;
+}
+
+#ifdef HAVE_LIBPCRE
+#define OVECCOUNT 30
+/* Matches a PCRE regex.  */
+bool
+match_pcre_regex (const void *regex, const char *str)
+{
+  int l = strlen (str);
+  int ovector[OVECCOUNT];
+
+  int rc = pcre_exec ((pcre *) regex, 0, str, l, 0, 0, ovector, OVECCOUNT);
+  if (rc == PCRE_ERROR_NOMATCH)
+    return false;
+  else if (rc < 0)
+    {
+      logprintf (LOG_VERBOSE, _("Error while matching %s: %d\n"),
+                 quote (str), rc);
+      return false;
+    }
+  else
+    return true;
+}
+#undef OVECCOUNT
+#endif
+
+/* Matches a POSIX regex.  */
+bool
+match_posix_regex (const void *regex, const char *str)
+{
+  int rc = regexec ((regex_t *) regex, str, 0, NULL, 0);
+  if (rc == REG_NOMATCH)
+    return false;
+  else if (rc == 0)
+    return true;
+  else
+    {
+      int errbuf_size = regerror (rc, opt.acceptregex, NULL, 0);
+      char *errbuf = xmalloc (errbuf_size);
+      errbuf_size = regerror (rc, opt.acceptregex, errbuf, errbuf_size);
+      logprintf (LOG_VERBOSE, _("Error while matching %s: %d\n"),
+                 quote (str), rc);
+      xfree (errbuf);
+      return false;
+    }
+}
+
 #undef IS_ASCII
 #undef NEXT_CHAR
 
