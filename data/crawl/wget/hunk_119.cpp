      become apparent later.  */
   if (*respline != '2')
     {
-      xfree (respline);
       if (res != -1)
         logprintf (LOG_NOTQUIET, "%s (%s) - ", tms, tmrate);
       logputs (LOG_NOTQUIET, _("Data transfer aborted.\n"));
+#ifdef HAVE_SSL
+      if (!c_strncasecmp (respline, "425", 3) && u->scheme == SCHEME_FTPS)
+        {
+          logputs (LOG_NOTQUIET, "FTPS server rejects new SSL sessions in the data connection.\n");
+          xfree (respline);
+          return FTPRESTFAIL;
+        }
+#endif
+      xfree (respline);
       return FTPRETRINT;
     }
   xfree (respline);
