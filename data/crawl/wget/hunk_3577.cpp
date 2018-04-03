       if (opt.spider)
 	{
 	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode, hstat.error);
+	  FREE_MAYBE (dummy);
 	  return RETROK;
 	}
 
-      /* It is now safe to free the remainder of hstat, since the
-	 strings within it will no longer be used.  */
-      FREEHSTAT (hstat);
-
       tmrate = rate (hstat.len - hstat.restval, hstat.dltime, 0);
 
       if (hstat.len == hstat.contlen)
