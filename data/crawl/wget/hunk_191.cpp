                 break;
 
               default:
-                /* Can't happen. */
-                assert (1);
+                logprintf (LOG_ALWAYS, _("Logically impossible section reached in getftp()"));
+                logprintf (LOG_ALWAYS, _("cwd_count: %d\ncwd_start: %d\ncwd_end: %d\n"),
+                                         cwd_count, cwd_start, cwd_end);
+                abort ();
             }
 
           if (!opt.server_response)
