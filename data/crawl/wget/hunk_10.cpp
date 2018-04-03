     to_encoding = nl_langinfo (CODESET);
 
   cd = iconv_open (to_encoding, from_encoding);
-  if (cd == (iconv_t)(-1))
-    logprintf (LOG_VERBOSE, _("Conversion from %s to %s isn't supported\n"),
-	       quote (from_encoding), quote (to_encoding));
+  if (cd == (iconv_t) (-1))
+    logprintf (LOG_VERBOSE, _ ("Conversion from %s to %s isn't supported\n"),
+               quote (from_encoding), quote (to_encoding));
   else
     {
       inlen = strlen (fname);
