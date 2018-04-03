                   if (finished)
                     {
                       logprintf (LOG_NONVERBOSE, 
-                                 _("%s URL:%s %2d %s\n"), 
+                                 _("%s URL: %s %2d %s\n"), 
                                  tms, u->url, hstat.statcode,
                                  hstat.message ? quotearg_style (escape_quoting_style, hstat.message) : "");
                       goto exit;
