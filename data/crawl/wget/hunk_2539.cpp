     {
       xfree (respline);
       if (res != -1)
-	logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
+        logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
       logputs (LOG_NOTQUIET, _("Data transfer aborted.\n"));
       return FTPRETRINT;
     }
