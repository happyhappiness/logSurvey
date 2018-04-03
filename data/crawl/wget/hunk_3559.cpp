                   /* Remote file is newer or sizes cannot be matched */
                   logprintf (LOG_VERBOSE, _("\
 Remote file is newer than local file `%s' -- retrieving.\n\n"),
-                             u->local);
+                             con->target);
                 }
               else
                 {
