   for (t = url; *t; t++)
     {
       char *filename = NULL, *redirected_URL = NULL;
-      int dt;
+      int dt, url_err;
+      struct url *url_parsed = url_parse (*t, &url_err);
 
-      if ((opt.recursive || opt.page_requisites)
-          && (url_scheme (*t) != SCHEME_FTP || url_uses_proxy (*t)))
+      if (!url_parsed)
         {
-          int old_follow_ftp = opt.follow_ftp;
+          char *error = url_error (*t, url_err);
+          logprintf (LOG_NOTQUIET, "%s: %s.\n",*t, error);
+          xfree (error);
+          status = URLERROR;
+        }
+      else
+        {
+          if ((opt.recursive || opt.page_requisites)
+              && (url_scheme (*t) != SCHEME_FTP || url_uses_proxy (url_parsed)))
+            {
+              int old_follow_ftp = opt.follow_ftp;
 
-          /* Turn opt.follow_ftp on in case of recursive FTP retrieval */
-          if (url_scheme (*t) == SCHEME_FTP) 
-            opt.follow_ftp = 1;
+              /* Turn opt.follow_ftp on in case of recursive FTP retrieval */
+              if (url_scheme (*t) == SCHEME_FTP) 
+                opt.follow_ftp = 1;
           
-          status = retrieve_tree (*t);
+              status = retrieve_tree (url_parsed);
 
-          opt.follow_ftp = old_follow_ftp;
-        }
-      else
-        status = retrieve_url (*t, &filename, &redirected_URL, NULL, &dt, opt.recursive);
+              opt.follow_ftp = old_follow_ftp;
+            }
+          else
+            status = retrieve_url (url_parsed, *t, &filename, &redirected_URL, NULL, &dt, opt.recursive);
 
-      if (opt.delete_after && file_exists_p(filename))
-        {
-          DEBUGP (("Removing file due to --delete-after in main():\n"));
-          logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
-          if (unlink (filename))
-            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+          if (opt.delete_after && file_exists_p(filename))
+            {
+              DEBUGP (("Removing file due to --delete-after in main():\n"));
+              logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
+              if (unlink (filename))
+                logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+            }
+          xfree_null (redirected_URL);
+          xfree_null (filename);
+          url_free (url_parsed);
         }
-
-      xfree_null (redirected_URL);
-      xfree_null (filename);
     }
 
   /* And then from the input file, if any.  */
