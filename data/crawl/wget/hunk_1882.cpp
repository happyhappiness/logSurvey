           break;
         }       /* switch */
 
+
+      /* 2004-12-15 SMS.
+       * Set permissions _before_ setting the times, as setting the
+       * permissions changes the modified-time, at least on VMS.
+       * Also, use the opt.output_document name here, too, as
+       * appropriate.  (Do the test once, and save the result.)
+       */
+
+      /* #### This code repeats in http.c and ftp.c.  Move it to a
+         function!  */
+      actual_target = NULL;
+      if (opt.output_document)
+        {
+          if (output_stream_regular)
+            actual_target = opt.output_document;
+        }
+      else
+        actual_target = con->target;
+
+      /* If downloading a plain file, set valid (non-zero) permissions. */
+      if (dlthis && (actual_target != NULL) && (f->type == FT_PLAINFILE))
+        {
+          if (f->perms)
+            chmod (actual_target, f->perms);
+          else
+            DEBUGP (("Unrecognized permissions for %s.\n", actual_target));
+        }
+
       /* Set the time-stamp information to the local file.  Symlinks
          are not to be stamped because it sets the stamp on the
          original.  :( */
-      if (!(f->type == FT_SYMLINK && !opt.retr_symlinks)
-          && f->tstamp != -1
-          && dlthis
-          && file_exists_p (con->target))
+
+      if (actual_target != NULL)
         {
-          /* #### This code repeats in http.c and ftp.c.  Move it to a
-             function!  */
-          const char *fl = NULL;
-          if (opt.output_document)
+          if (!(f->type == FT_SYMLINK && !opt.retr_symlinks)
+              && f->tstamp != -1
+              && dlthis
+              && file_exists_p (con->target))
             {
-              if (output_stream_regular)
-                fl = opt.output_document;
+              touch (actual_target, f->tstamp);
             }
-          else
-            fl = con->target;
-          if (fl)
-            touch (fl, f->tstamp);
-        }
-      else if (f->tstamp == -1)
-        logprintf (LOG_NOTQUIET, _("%s: corrupt time-stamp.\n"), con->target);
-
-      if (f->perms && f->type == FT_PLAINFILE && dlthis)
-        {
-          if (opt.preserve_perm)
-            chmod (con->target, f->perms);
+          else if (f->tstamp == -1)
+            logprintf (LOG_NOTQUIET, _("%s: corrupt time-stamp.\n"),
+            actual_target);
         }
-      else
-        DEBUGP (("Unrecognized permissions for %s.\n", con->target));
 
       xfree (con->target);
       con->target = old_target;
