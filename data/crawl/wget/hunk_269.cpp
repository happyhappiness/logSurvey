       if (!opt.rejectregex)
         exit (1);
     }
+  if (opt.post_data || opt.post_file_name)
+    {
+      if (opt.post_data && opt.post_file_name)
+        {
+          fprintf (stderr, _("You cannot specify both --post-data and --post-file.\n"));
+          exit (1);
+        }
+      else if (opt.method)
+        {
+          fprintf (stderr, _("You cannot use --post-data or --post-file along with --method. "
+                             "--method expects data through --body-data and --body-file options"));
+          exit (1);
+        }
+    }
+  if (opt.body_data || opt.body_file)
+    {
+      if (!opt.method)
+        {
+          fprintf (stderr, _("You must specify a method through --method=HTTPMethod "
+                              "to use with --body-data or --body-file.\n"));
+          exit (1);
+        }
+      else if (opt.body_data && opt.body_file)
+        {
+          fprintf (stderr, _("You cannot specify both --body-data and --body-file.\n"));
+          exit (1);
+        }
+    }
 
 #ifdef ENABLE_IRI
   if (opt.enable_iri)
