   cd = iconv_open (tocode, fromcode);
   if (cd == (iconv_t)(-1))
     {
-      logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
-                 quote (opt.locale), quote ("UTF-8"));
+      logprintf (LOG_VERBOSE, _("Conversion from %s to UTF-8 isn't supported\n"),
+                 quote (opt.locale));
+      *out = NULL;
       return false;
     }
 