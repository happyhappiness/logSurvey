 
       if (opt.encoding_remote && !check_encoding_name (opt.encoding_remote))
         opt.encoding_remote = NULL;
-
-      /*logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));*/
     }
 #else
   if (opt.enable_iri || opt.locale || opt.encoding_remote)
