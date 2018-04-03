           /* If opt.noclobber is turned on and file already exists, do not
              retrieve the file. But if the output_document was given, then this
              test was already done and the file didn't exist. Hence the !opt.output_document */
-          logprintf (LOG_VERBOSE, _("\
-File %s already there; not retrieving.\n\n"), quote (hs->local_file));
-          /* If the file is there, we suppose it's retrieved OK.  */
-          *dt |= RETROKF;
-
-          /* #### Bogusness alert.  */
-          /* If its suffix is "html" or "htm" or similar, assume text/html.  */
-          if (has_html_suffix_p (hs->local_file))
-            *dt |= TEXTHTML;
-
+          get_file_flags (hs->local_file, dt);
           xfree (head);
           xfree_null (message);
           return RETRUNNEEDED;
