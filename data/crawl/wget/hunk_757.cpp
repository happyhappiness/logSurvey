 #ifdef ENABLE_IRI
   if (opt.enable_iri)
     {
+      if (opt.locale && !check_encoding_name(opt.locale))
+        opt.locale = NULL;
+
       if (!opt.locale)
         opt.locale = find_locale ();
 
-      /* sXXXav : check given locale and remote encoding */
+      if (opt.encoding_remote && !check_encoding_name(opt.encoding_remote))
+        opt.encoding_remote = NULL;
 
       logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));
     }
 src/ChangeLog | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
