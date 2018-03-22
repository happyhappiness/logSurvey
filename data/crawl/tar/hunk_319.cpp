 #undef CURRENT_FILE_NAME
 }
 
-/* Fix the status of all directories whose statuses need fixing.  */
-void
-apply_delayed_set_stat (void)
+/* Extract the symbolic links whose final extraction were delayed.  */
+static void
+apply_delayed_symlinks (void)
 {
-  apply_nonancestor_delayed_set_stat ("");
+  struct delayed_symlink *p;
+  struct delayed_symlink *next;
+
+  for (p = delayed_symlink_head; p; p = next)
+    {
+      char const *file = p->names;
+      struct stat st;
+
+      /* Before doing anything, make sure the placeholder file is still
+	 there.  If the placeholder isn't there, don't worry about it, as
+	 it may have been removed by a later extraction.  */
+      if (lstat (file, &st) == 0
+	  && st.st_dev == p->dev
+	  && st.st_ino == p->ino
+	  && st.st_mtime == p->mtime)
+	{
+	  if (unlink (file) != 0)
+	    unlink_error (file);
+	  else
+	    {
+	      char const *contents = file + strlen (file) + 1;
+	      if (symlink (contents, file) != 0)
+		symlink_error (contents, file);
+	      else
+		{
+		  st.st_uid = p->uid;
+		  st.st_gid = p->gid;
+		  set_stat (file, &st, 0, 0, SYMTYPE);
+		}
+	    }
+	}
+
+      next = p->next;
+      free (p);
+    }
+
+  delayed_symlink_head = 0;
 }
 
-/* Fix the statuses of all directories whose statuses need fixing, and
-   which are not ancestors of FILE_NAME.  */
+/* Finish the extraction of an archive.  */
 void
-apply_nonancestor_delayed_set_stat (char const *file_name)
+extract_finish (void)
 {
-  size_t file_name_len = strlen (file_name);
-
-  while (delayed_set_stat_head)
-    {
-      struct delayed_set_stat *data = delayed_set_stat_head;
-      if (data->file_name_len < file_name_len
-	  && file_name[data->file_name_len] == '/'
-	  && memcmp (file_name, data->file_name, data->file_name_len) == 0)
-	break;
-      delayed_set_stat_head = data->next;
-      set_stat (data->file_name, &data->stat_info,
-		data->invert_permissions, data->permstatus, DIRTYPE);
-      free (data);
-    }
+  /* Apply delayed symlinks last, so that they don't affect
+     delayed directory status-setting.  */
+  apply_nonancestor_delayed_set_stat ("");
+  apply_delayed_symlinks ();
 }
 
 void
 fatal_exit (void)
 {
-  apply_delayed_set_stat ();
+  extract_finish ();
   error (TAREXIT_FAILURE, 0, _("Error is not recoverable: exiting now"));
   abort ();
 }
