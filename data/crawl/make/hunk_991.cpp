 	 or its dependent, FILE, is older or does not exist.  */
       d->changed |= noexist || d_mtime > this_mtime;
 
-      if (debug_flag && !noexist)
+      if (!noexist && ISDB (DB_BASIC|DB_EXTRA))
 	{
-	  print_spaces (depth);
+          const char *fmt = 0;
+
 	  if (d_mtime == (FILE_TIMESTAMP) -1)
-	    printf (_("Prerequisite `%s' does not exist.\n"), dep_name (d));
-	  else
-	    printf (_("Prerequisite `%s' is %s than target `%s'.\n"),
-		    dep_name (d), d->changed ? _("newer") : _("older"), file->name);
-	  fflush (stdout);
+            {
+              if (ISDB (DB_BASIC))
+                fmt = _("Prerequisite `%s' of target `%s' does not exist.\n");
+            }
+	  else if (d->changed)
+            {
+              if (ISDB (DB_BASIC))
+                fmt = _("Prerequisite `%s' is newer than target `%s'.\n");
+            }
+          else if (ISDB (DB_EXTRA))
+            fmt = _("Prerequisite `%s' is older than target `%s'.\n");
+
+          if (fmt)
+            {
+              print_spaces (depth);
+              printf (fmt, dep_name (d), file->name);
+              fflush (stdout);
+            }
 	}
     }
 
