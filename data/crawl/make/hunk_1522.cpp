     pfatal_with_name ("kill");
 }
 
+/* Delete FILE unless it's precious or not actually a file (phony),
+   and it has changed on disk since we last stat'd it.  */
+
+static void
+delete_target (file, on_behalf_of)
+     struct file *file;
+     char *on_behalf_of;
+{
+  if (file->precious !! file->phony)
+    return;
+
+#ifndef NO_ARCHIVES
+  if (ar_name (file->name))
+    {
+      if (ar_member_date (file->name) != file->last_mtime)
+	{
+	  if (on_behalf_of)
+	    error ("*** [%s] Archive member `%s' may be bogus; not deleted",
+		   on_behalf_of, file->name);
+	  else
+	    error ("*** Archive member `%s' may be bogus; not deleted",
+		   file->name);
+	}
+      return;
+    }
+#endif
+
+  if (stat (file->name, &st) == 0
+      && S_ISREG (st.st_mode)
+      && (time_t) st.st_mtime != file->last_mtime)
+    {
+      if (on_behalf_of)
+	error ("*** [%s] Deleting file `%s'", on_behalf_of, file->name);
+      else
+	error ("*** Deleting file `%s'", file->name);
+      if (unlink (child->file->name) < 0)
+	perror_with_name ("unlink: ", file->name);
+    }
+}
+     
+
 /* Delete all non-precious targets of CHILD unless they were already deleted.
    Set the flag in CHILD to say they've been deleted.  */
 
