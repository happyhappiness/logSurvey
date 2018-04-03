       xfree (mynewloc);
       mynewloc = construced_newloc;
 
-      reset_utf8_encode ();
+      /* Reset UTF-8 encoding state, keep the URI encoding and reset
+         the content encoding. */
+      iri->utf8_encode = opt.enable_iri;
+      set_content_encoding (iri, NULL);
 
       /* Now, see if this new location makes sense. */
-      newloc_parsed = url_parse (mynewloc, &up_error_code);
+      newloc_parsed = url_parse (mynewloc, &up_error_code, iri);
       if (!newloc_parsed)
         {
           logprintf (LOG_NOTQUIET, "%s: %s.\n", escnonprint_uri (mynewloc),
