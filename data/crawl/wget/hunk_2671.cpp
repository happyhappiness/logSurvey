       if (opt.verbose)
         {
           char *hurl = url_string (u, true);
-          char tmp[256];
-          strcpy (tmp, "        ");
-          if (count > 1)
-            sprintf (tmp, _("(try:%2d)"), count);
-          logprintf (LOG_VERBOSE, "--%s--  %s\n  %s\n",
-                     tms, hurl, tmp);
+          logprintf (LOG_VERBOSE, "--%s--  %s\n",
+                     tms, hurl);
+          
+          if (count > 1) 
+            {
+              char tmp[256];
+              sprintf (tmp, _("(try:%2d)"), count);
+              logprintf (LOG_VERBOSE, "  %s", tmp);
+            }
+          else 
+            {
+              logprintf (LOG_VERBOSE, "        ");
+            }
+          
+          if (hstat.local_file) 
+            {
+              logprintf (LOG_VERBOSE, " => `%s'\n", 
+                         HYPHENP (hstat.local_file) ? "STDOUT" : hstat.local_file);
+            }
+          else
+            {
+              logprintf (LOG_VERBOSE, "\n");
+            }
+          
 #ifdef WINDOWS
           ws_changetitle (hurl);
 #endif
