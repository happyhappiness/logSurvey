           url_text = merged;
         }
 
-      url = url_parse (url_text, &up_error_code, &utf8_encode);
+      set_ugly_no_encode (true);
+      url = url_parse (url_text, &up_error_code);
+      set_ugly_no_encode (false);
       if (!url)
         {
           logprintf (LOG_NOTQUIET, _("%s: Invalid URL %s: %s\n"),
