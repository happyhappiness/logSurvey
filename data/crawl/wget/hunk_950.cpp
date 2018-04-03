           url_text = merged;
         }
 
-      url = url_parse (url_text, &up_error_code);
+      url = url_parse (url_text, &up_error_code, &utf8_encode);
       if (!url)
         {
           logprintf (LOG_NOTQUIET, _("%s: Invalid URL %s: %s\n"),
