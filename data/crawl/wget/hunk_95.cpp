   cd = iconv_open (tocode, fromcode);
   if (cd == (iconv_t)(-1))
     {
-      logprintf (LOG_VERBOSE, _("Conversion from %s to UTF-8 isn't supported\n"),
-                 quote (opt.locale));
+      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
+                 quote (fromcode), quote (tocode));
       *out = NULL;
       return false;
     }
