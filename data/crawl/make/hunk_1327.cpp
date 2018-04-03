       if (!file->dontcare)
         {
           if (file->parent == 0)
-            error (msg_noparent, "*** ", file->name, ".");
+            error (NILF, msg_noparent, "*** ", file->name, ".");
           else
-            error (msg_parent, "*** ",
+            error (NILF, msg_parent, "*** ",
                    file->name, file->parent->name, ".");
           file->shownerror = 1;
         }
