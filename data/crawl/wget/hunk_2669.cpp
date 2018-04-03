       if (opt.verbose)
         {
           char *hurl = url_string (u, true);
-          logprintf (LOG_VERBOSE, "--%s--  %s\n",
-                     tms, hurl);
           
           if (count > 1) 
             {
               char tmp[256];
               sprintf (tmp, _("(try:%2d)"), count);
-              logprintf (LOG_VERBOSE, "  %s", tmp);
+              logprintf (LOG_NOTQUIET, "--%s--  %s  %s\n\n",
+                         tms, tmp, hurl);
             }
           else 
             {
-              logprintf (LOG_VERBOSE, "        ");
-            }
-          
-          if (hstat.local_file) 
-            {
-              logprintf (LOG_VERBOSE, " => `%s'\n", 
-                         HYPHENP (hstat.local_file) ? "STDOUT" : hstat.local_file);
-            }
-          else
-            {
-              logprintf (LOG_VERBOSE, "\n");
+              logprintf (LOG_NOTQUIET, "--%s--  %s\n\n",
+                         tms, hurl);
             }
           
 #ifdef WINDOWS
