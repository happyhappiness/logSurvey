       xfree (mynewloc);
       mynewloc = construced_newloc;
 
-      utf8_encoded = opt.enable_iri;
+      reset_utf8_encode ();
 
       /* Now, see if this new location makes sense. */
-      newloc_parsed = url_parse (mynewloc, &up_error_code, &utf8_encoded);
+      newloc_parsed = url_parse (mynewloc, &up_error_code);
       if (!newloc_parsed)
         {
           logprintf (LOG_NOTQUIET, "%s: %s.\n", escnonprint_uri (mynewloc),
