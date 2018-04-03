   if (file)
     *file = NULL;
 
-  reset_utf8_encode ();
-
  second_try:
-  u = url_parse (url, &up_error_code);
+  u = url_parse (url, &up_error_code, iri);
   if (!u)
     {
       logprintf (LOG_NOTQUIET, "%s: %s.\n", url, url_error (up_error_code));
