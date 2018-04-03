         }
       /* End of time-stamping section. */
 
-      if (opt.spider)
+      if (opt.spider && !opt.recursive)
         {
           logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
                      escnonprint (hstat.error));
