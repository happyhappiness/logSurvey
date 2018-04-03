       file->cmds = default_file->cmds;
     }
 
-  /* Update all non-intermediate files we depend on, if necessary,
-     and see whether any of them is more recent than this file.  */
+  /* Update all non-intermediate files we depend on, if necessary, and see
+     whether any of them is more recent than this file.  We need to walk our
+     deps, AND the deps of any also_make targets to ensure everything happens
+     in the correct order.  */
 
-  lastd = 0;
-  d = file->deps;
-  while (d != 0)
+  amake.file = file;
+  amake.next = file->also_make;
+  ad = &amake;
+  while (ad)
     {
-      FILE_TIMESTAMP mtime;
-      int maybe_make;
-      int dontcare = 0;
+      struct dep *lastd = 0;
 
-      check_renamed (d->file);
+      /* Find the deps we're scanning */
+      d = ad->file->deps;
+      ad = ad->next;
 
-      mtime = file_mtime (d->file);
-      check_renamed (d->file);
+      while (d)
+        {
+          FILE_TIMESTAMP mtime;
+          int maybe_make;
+          int dontcare = 0;
 
-      if (is_updating (d->file))
-	{
-	  error (NILF, _("Circular %s <- %s dependency dropped."),
-		 file->name, d->file->name);
-	  /* We cannot free D here because our the caller will still have
-	     a reference to it when we were called recursively via
-	     check_dep below.  */
-	  if (lastd == 0)
-	    file->deps = d->next;
-	  else
-	    lastd->next = d->next;
-	  d = d->next;
-	  continue;
-	}
+          check_renamed (d->file);
 
-      d->file->parent = file;
-      maybe_make = must_make;
+          mtime = file_mtime (d->file);
+          check_renamed (d->file);
 
-      /* Inherit dontcare flag from our parent. */
-      if (rebuilding_makefiles)
-        {
-          dontcare = d->file->dontcare;
-          d->file->dontcare = file->dontcare;
-        }
+          if (is_updating (d->file))
+            {
+              error (NILF, _("Circular %s <- %s dependency dropped."),
+                     file->name, d->file->name);
+              /* We cannot free D here because our the caller will still have
+                 a reference to it when we were called recursively via
+                 check_dep below.  */
+              if (lastd == 0)
+                file->deps = d->next;
+              else
+                lastd->next = d->next;
+              d = d->next;
+              continue;
+            }
 
+          d->file->parent = file;
+          maybe_make = must_make;
 
-      dep_status |= check_dep (d->file, depth, this_mtime, &maybe_make);
+          /* Inherit dontcare flag from our parent. */
+          if (rebuilding_makefiles)
+            {
+              dontcare = d->file->dontcare;
+              d->file->dontcare = file->dontcare;
+            }
 
-      /* Restore original dontcare flag. */
-      if (rebuilding_makefiles)
-        d->file->dontcare = dontcare;
+          dep_status |= check_dep (d->file, depth, this_mtime, &maybe_make);
 
-      if (! d->ignore_mtime)
-        must_make = maybe_make;
+          /* Restore original dontcare flag. */
+          if (rebuilding_makefiles)
+            d->file->dontcare = dontcare;
 
-      check_renamed (d->file);
+          if (! d->ignore_mtime)
+            must_make = maybe_make;
 
-      {
-	register struct file *f = d->file;
-	if (f->double_colon)
-	  f = f->double_colon;
-	do
-	  {
-	    running |= (f->command_state == cs_running
-			|| f->command_state == cs_deps_running);
-	    f = f->prev;
-	  }
-	while (f != 0);
-      }
+          check_renamed (d->file);
+
+          {
+            register struct file *f = d->file;
+            if (f->double_colon)
+              f = f->double_colon;
+            do
+              {
+                running |= (f->command_state == cs_running
+                            || f->command_state == cs_deps_running);
+                f = f->prev;
+              }
+            while (f != 0);
+          }
 
-      if (dep_status != 0 && !keep_going_flag)
-	break;
+          if (dep_status != 0 && !keep_going_flag)
+            break;
 
-      if (!running)
-        /* The prereq is considered changed if the timestamp has changed while
-           it was built, OR it doesn't exist.  */
-	d->changed = ((file_mtime (d->file) != mtime)
-                      || (mtime == NONEXISTENT_MTIME));
+          if (!running)
+            /* The prereq is considered changed if the timestamp has changed while
+               it was built, OR it doesn't exist.  */
+            d->changed = ((file_mtime (d->file) != mtime)
+                          || (mtime == NONEXISTENT_MTIME));
 
-      lastd = d;
-      d = d->next;
+          lastd = d;
+          d = d->next;
+        }
     }
 
   /* Now we know whether this target needs updating.
