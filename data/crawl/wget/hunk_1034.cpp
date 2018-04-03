 #ifdef ENABLE_IRI
   if (opt.enable_iri)
     {
-      if (opt.locale && !check_encoding_name(opt.locale))
+      if (opt.locale && !check_encoding_name (opt.locale))
         opt.locale = NULL;
 
       if (!opt.locale)
         opt.locale = find_locale ();
 
-      if (opt.encoding_remote && !check_encoding_name(opt.encoding_remote))
+      if (opt.encoding_remote && !check_encoding_name (opt.encoding_remote))
         opt.encoding_remote = NULL;
 
-      logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));
+      /*logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));*/
     }
 #else
   if (opt.enable_iri || opt.locale || opt.encoding_remote)
