     = "%sNo rule to make target `%s'%s";
   static const char msg_parent[]
     = "%sNo rule to make target `%s', needed by `%s'%s";
+
   if (keep_going_flag || file->dontcare)
     {
-      if (!file->dontcare && !file->shownerror)
+      /* If the previous attempt was made while we were creating
+         makefiles, but we aren't anymore, print an error now.  */
+      if (!file->dontcare
+          || (file->mfile_status && !updating_makefiles))
         {
           if (file->parent == 0)
             error (NILF, msg_noparent, "*** ", file->name, ".");
           else
             error (NILF, msg_parent, "*** ",
                    file->name, file->parent->name, ".");
-          file->shownerror = 1;
         }
       file->update_status = 2;
+      file->mfile_status = updating_makefiles;
     }
+  else if (file->parent == 0)
+    fatal (NILF, msg_noparent, "", file->name, "");
   else
-    {
-      if (file->parent == 0)
-        fatal (NILF, msg_noparent, "", file->name, "");
-      else
-        fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
-    }
+    fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
 }
 
 /* If FILE is not up to date, execute the commands for it.
