                    opt.input_filename);
     }
 
+#ifdef HAVE_METALINK
+  /* Finally, from metlink file, if any.  */
+  if (opt.input_metalink)
+    {
+      metalink_error_t meta_err;
+      uerr_t retr_err;
+      metalink_t *metalink;
+
+      meta_err = metalink_parse_file (opt.input_metalink, &metalink);
+
+      if (meta_err)
+        {
+          logprintf (LOG_NOTQUIET, _("Unable to parse metalink file %s.\n"),
+                     opt.input_metalink);
+          retr_err = METALINK_PARSE_ERROR;
+        }
+      else
+        {
+          retr_err = retrieve_from_metalink (metalink);
+          if (retr_err != RETROK)
+            {
+              logprintf (LOG_NOTQUIET,
+                         _("Could not download all resources from %s.\n"),
+                         quote (opt.input_metalink));
+            }
+        }
+      inform_exit_status (retr_err);
+      metalink_delete (metalink);
+    }
+#endif /* HAVE_METALINK */
+
   /* Print broken links. */
   if (opt.recursive && opt.spider)
     print_broken_links ();
