 
   DEBUGPR ("Must remake target `%s'.\n");
 
-  /* It needs to be remade.  If it's VPATH and not GPATH, toss the VPATH */
+  /* It needs to be remade.  If it's VPATH and not reset via GPATH, toss the
+     VPATH */
   if (!streq(file->name, file->hname))
     {
-      char *name = file->name;
-
-      if (gpath_search (&name, NULL))
-        {
-          register struct file *fp = file;
-
-          /* Since we found the file on GPATH, convert it to use the
-             VPATH filename. */
-          while (fp)
-            {
-              fp->name = fp->hname;
-              fp = fp->prev;
-            }
-          DEBUGPR ("  Using VPATH `%s' due to GPATH.\n");
-        }
-      else
+      if (debug_flag)
         {
-          if (debug_flag)
-            {
-              print_spaces (depth);
-              printf("  Ignoring VPATH name `%s'.\n", file->hname);
-              fflush(stdout);
-            }
-          file->ignore_vpath = 1;
+          print_spaces (depth);
+          printf("  Ignoring VPATH name `%s'.\n", file->hname);
+          fflush(stdout);
         }
+      file->ignore_vpath = 1;
     }
 
   /* Now, take appropriate actions to remake the file.  */
