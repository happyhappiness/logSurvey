        (f->type == FT_PLAINFILE) && opt.preserve_perm)
         {
           if (f->perms)
-            chmod (actual_target, f->perms);
+            {
+              if (chmod (actual_target, f->perms))
+                logprintf (LOG_NOTQUIET,
+                           _("Failed to set permissions for %s.\n"),
+                           actual_target);
+            }
           else
             DEBUGP (("Unrecognized permissions for %s.\n", actual_target));
         }
