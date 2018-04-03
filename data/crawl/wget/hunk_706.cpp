   if (file)
     *file = NULL;
 
-  u = url_parse (url, &up_error_code);
-  if (!u)
-    {
-      char *error = url_error (url, up_error_code);
-      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, error);
-      xfree (url);
-      xfree (error);
-      return URLERROR;
-    }
-
   if (!refurl)
     refurl = opt.referer;
 
