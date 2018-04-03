 
       output_stream = NULL;
 
+      mfc++;
+
       /* The directory prefix for opt.metalink_over_http is handled by
          src/url.c (url_file_name), do not add it a second time.  */
       if (!metalink->origin && opt.dir_prefix && strlen (opt.dir_prefix))
-        filename = aprintf ("%s/%s", opt.dir_prefix, mfile->name);
+        planname = aprintf ("%s/%s", opt.dir_prefix, mfile->name);
       else
-        filename = xstrdup (mfile->name);
+        planname = xstrdup (mfile->name);
 
-      DEBUGP (("Processing metalink file %s...\n", quote (mfile->name)));
+      /* With Metalink/HTTP, trust the metalink file name (from cli).
+         With --trust-server-names, trust the Metalink/XML file name,
+         otherwise, use the basename of --input-metalink followed by
+         the metalink file counter as suffix.  */
+      if (metalink->origin || opt.trustservernames)
+        {
+          trsrname = xstrdup (mfile->name);
+        }
+      else
+        {
+          trsrname = xstrdup (get_metalink_basename (opt.input_metalink));
+          append_suffix_number (&trsrname, ".#", mfc);
+        }
+
+      /* Add the directory prefix for opt.input_metalink.  */
+      if (!metalink->origin && opt.dir_prefix && strlen (opt.dir_prefix))
+        filename = aprintf ("%s/%s", opt.dir_prefix, trsrname);
+      else
+        filename = xstrdup (trsrname);
 
       /* Enforce libmetalink's metalink_check_safe_path().  */
       basename = get_metalink_basename (filename);
       safename = metalink_check_safe_path (filename) ? filename : basename;
 
-      if (filename != safename)
-        logprintf (LOG_NOTQUIET,
-                   _("Unsafe metalink file %s. Stripping directory...\n"),
-                   quote (filename));
-
-      if (!basename)
+      DEBUGP (("Processing metalink file %s...\n", quote (mfile->name)));
+      DEBUGP (("\n"));
+      DEBUGP (("  %s\n", metatpy));
+      DEBUGP (("\n"));
+      DEBUGP (("  --trust-server-names   %s\n", opt.trustservernames ? "true" : "false"));
+      DEBUGP (("  --directory-prefix     %s\n", quote (opt.dir_prefix ? opt.dir_prefix : "")));
+      DEBUGP (("\n"));
+      DEBUGP (("   Counted metalink file %u\n", mfc));
+      DEBUGP (("   Planned metalink file %s\n", quote (planname ? planname : "")));
+      DEBUGP (("   Trusted metalink file %s\n", quote (trsrname ? trsrname : "")));
+      DEBUGP (("   Current metalink file %s\n", quote (filename ? filename : "")));
+      DEBUGP (("   Cleaned metalink file %s\n", quote (basename ? basename : "")));
+      DEBUGP (("   Secured metalink file %s\n", quote (safename ? safename : "")));
+      DEBUGP (("\n"));
+
+      /* Verify if the planned metalink file name is safe.  */
+      if (!safename || strcmp (planname, safename))
         {
           logprintf (LOG_NOTQUIET,
-                     _("Rejecting metalink file. Invalid basename.\n"));
-          xfree (filename);
-          continue;
+                     _("[--trust-server-names %s, --directory-prefix=%s]\n"),
+                     (opt.trustservernames ? "true" : "false"),
+                     quote (opt.dir_prefix ? opt.dir_prefix : ""));
+          logprintf (LOG_NOTQUIET,
+                     _("Planned metalink file: %s\n"),
+                     quote (planname ? planname : ""));
+          logprintf (LOG_NOTQUIET,
+                     _("Secured metalink file: %s\n"),
+                     quote (safename ? safename : ""));
+          if (!safename)
+            {
+              logprintf (LOG_NOTQUIET,
+                         _("Rejecting metalink file. Unsafe name.\n"));
+              xfree (planname);
+              xfree (trsrname);
+              xfree (filename);
+              continue;
+            }
         }
 
       /* Resources are sorted by priority.  */
