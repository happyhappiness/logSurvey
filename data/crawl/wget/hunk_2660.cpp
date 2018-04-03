   else
     fp = output_stream;
 
+  /* Print fetch message, if opt.verbose.  */
+  if (opt.verbose)
+    {
+      logprintf (LOG_NOTQUIET, _("Saving to: `%s'\n"), 
+                 HYPHENP (hs->local_file) ? "STDOUT" : hs->local_file);
+    }
+    
   /* This confuses the timestamping code that checks for file size.
      #### The timestamping code should be smarter about file size.  */
   if (opt.save_headers && hs->restval == 0)
