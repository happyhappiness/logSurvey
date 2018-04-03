     = "%sNo rule to make target `%s', needed by `%s'%s";
   if (keep_going_flag || file->dontcare)
     {
-      if (!file->dontcare)
+      if (!file->dontcare && !file->shownerror)
         {
           if (file->parent == 0)
             error (NILF, msg_noparent, "*** ", file->name, ".");
