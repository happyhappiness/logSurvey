   u = url_parse (url, &up_error_code);
   if (!u)
     {
-      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, url_error (up_error_code));
+      char *error = url_error (url, up_error_code);
+      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, error);
       xfree (url);
+      xfree (error);
       return URLERROR;
     }
 
