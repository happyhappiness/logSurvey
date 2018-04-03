      become apparent later.  */
   if (*respline != '2')
     {
-      free (respline);
+      xfree (respline);
       if (res != -1)
 	logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
       logputs (LOG_NOTQUIET, _("Data transfer aborted.\n"));
       return FTPRETRINT;
     }
-  free (respline);
+  xfree (respline);
 
   if (res == -1)
     {
