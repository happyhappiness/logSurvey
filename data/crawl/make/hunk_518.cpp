           if (adjusted_now < adjusted_mtime)
             {
 #ifdef NO_FLOAT
-              error (NILF, _("Warning: File `%s' has modification time in the future"),
+              error (NILF, _("Warning: File '%s' has modification time in the future"),
                      file->name);
 #else
               double from_now =
