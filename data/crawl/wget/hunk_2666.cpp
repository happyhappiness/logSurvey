   /* Print fetch message, if opt.verbose.  */
   if (opt.verbose)
     {
-      logprintf (LOG_NOTQUIET, _("\nStoring resource in file: `%s'\n"), 
+      logprintf (LOG_NOTQUIET, _("Saving to: `%s'\n"), 
                  HYPHENP (hs->local_file) ? "STDOUT" : hs->local_file);
     }
     
