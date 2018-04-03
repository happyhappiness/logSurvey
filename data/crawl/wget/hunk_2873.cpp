       url = url_parse (url_text, &up_error_code);
       if (!url)
 	{
-	  logprintf (LOG_NOTQUIET, "%s: Invalid URL %s: %s\n",
+	  logprintf (LOG_NOTQUIET, _("%s: Invalid URL %s: %s\n"),
 		     file, url_text, url_error (up_error_code));
 	  xfree (url_text);
 	  continue;
