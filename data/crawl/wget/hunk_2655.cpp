 	logprintf (LOG_NOTQUIET, _("No URLs found in %s.\n"),
 		   opt.input_filename);
     }
+
+  /* Print broken links. */
+  if (opt.recursive && opt.spider)
+    {
+      print_broken_links();
+    }
+  
   /* Print the downloaded sum.  */
   if ((opt.recursive || opt.page_requisites
        || nurl > 1
