           con->csock = -1;
         }
       if (!opt.spider)
-        logprintf (LOG_VERBOSE, _("%s (%s) - %s saved [%s]\n\n"),
-                   tms, tmrate, quote (locf), number_to_static_string (len));
+        {
+          bool write_to_stdout = (opt.output_document && HYPHENP (opt.output_document));
+
+          logprintf (LOG_VERBOSE,
+                     write_to_stdout
+                     ? _("%s (%s) - written to stdout %s[%s]\n\n")
+                     : _("%s (%s) - %s saved [%s]\n\n"),
+                     tms, tmrate,
+                     write_to_stdout ? "" : quote (locf),
+                     number_to_static_string (len));
+        }
       if (!opt.verbose && !opt.quiet)
         {
           /* Need to hide the password from the URL.  The `if' is here
