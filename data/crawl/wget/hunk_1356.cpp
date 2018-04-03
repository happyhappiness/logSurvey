                                   || hstat.orig_file_size == hstat.contlen)
                                 {
                                   logprintf (LOG_VERBOSE, _("\
-Server file no newer than local file `%s' -- not retrieving.\n\n"),
-                                             hstat.orig_file_name);
+Server file no newer than local file %s -- not retrieving.\n\n"),
+                                             quote (hstat.orig_file_name));
                                   ret = RETROK;
                                   goto exit;
                                 }
