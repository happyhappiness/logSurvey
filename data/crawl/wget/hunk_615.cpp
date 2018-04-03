           logprintf (LOG_VERBOSE, _("No matches on pattern `%s'.\n"),
                      escnonprint (u->file));
         }
-      else /* GLOB_GETONE or GLOB_GETALL */
+      else if (action == GLOB_GETONE) /* GLOB_GETONE or GLOB_GETALL */
         {
           /* Let's try retrieving it anyway.  */
           con->st |= ON_YOUR_OWN;
           res = ftp_loop_internal (u, NULL, con);
           return res;
         }
+
+      /* If action == GLOB_GETALL, and the file list is empty, there's
+         no point in trying to download anything or in complaining about
+         it.  (An empty directory should not cause complaints.)
+      */
     }
   freefileinfo (start);
   if (opt.quota && total_downloaded_bytes > opt.quota)
