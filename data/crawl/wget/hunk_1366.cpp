                   /* Remote file is older, file sizes can be compared and
                      are both equal. */
                   logprintf (LOG_VERBOSE, _("\
-Remote file no newer than local file `%s' -- not retrieving.\n"), con->target);
+Remote file no newer than local file %s -- not retrieving.\n"), quote (con->target));
                   dlthis = false;
                 }
               else if (eq_size)
                 {
                   /* Remote file is newer or sizes cannot be matched */
                   logprintf (LOG_VERBOSE, _("\
-Remote file is newer than local file `%s' -- retrieving.\n\n"),
-                             con->target);
+Remote file is newer than local file %s -- retrieving.\n\n"),
+                             quote (con->target));
                 }
               else
                 {
