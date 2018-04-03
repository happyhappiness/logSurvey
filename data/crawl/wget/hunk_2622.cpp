         }
       /* End of time-stamping section. */
 
-      if (opt.spider && !opt.recursive)
-        {
-          logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode,
-                     escnonprint (hstat.error));
-          ret = RETROK;
-          goto exit;
-        }
-
       tmrate = retr_rate (hstat.rd_size, hstat.dltime);
       total_download_time += hstat.dltime;
 
