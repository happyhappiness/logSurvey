 }
 
 /* Fix the statuses of all directories whose statuses need fixing, and
-   which are not ancestors of FILE_NAME.  */
+   which are not ancestors of FILE_NAME.  If AFTER_SYMLINKS is
+   nonzero, do this for all such directories; otherwise, stop at the
+   first directory that is marked to be fixed up only after delayed
+   symlinks are applied.  */
 static void
-apply_nonancestor_delayed_set_stat (char const *file_name)
+apply_nonancestor_delayed_set_stat (char const *file_name, bool after_symlinks)
 {
   size_t file_name_len = strlen (file_name);
+  bool check_for_renamed_directories = 0;
 
   while (delayed_set_stat_head)
     {
       struct delayed_set_stat *data = delayed_set_stat_head;
-      if (data->file_name_len < file_name_len
-	  && file_name[data->file_name_len]
-	  && (ISSLASH (file_name[data->file_name_len])
-	      || ISSLASH (file_name[data->file_name_len - 1]))
-	  && memcmp (file_name, data->file_name, data->file_name_len) == 0)
+      bool skip_this_one = 0;
+      check_for_renamed_directories |= data->after_symlinks;
+      struct stat st;
+      struct stat const *current_stat_info = 0;
+
+      if (after_symlinks < data->after_symlinks
+	  || (data->file_name_len < file_name_len
+	      && file_name[data->file_name_len]
+	      && (ISSLASH (file_name[data->file_name_len])
+		  || ISSLASH (file_name[data->file_name_len - 1]))
+	      && memcmp (file_name, data->file_name, data->file_name_len) == 0))
 	break;
+
+      if (check_for_renamed_directories)
+	{
+	  current_stat_info = &st;
+	  if (stat (data->file_name, &st) != 0)
+	    {
+	      stat_error (data->file_name);
+	      skip_this_one = 1;
+	    }
+	  else if (! (st.st_dev == data->stat_info.st_dev
+		      && (st.st_ino == data->stat_info.st_ino)))
+	    {
+	      ERROR ((0, 0,
+		      _("%s: Directory renamed before its status could be extracted"),
+		      quotearg_colon (data->file_name)));
+	      skip_this_one = 1;
+	    }
+	}
+
+      if (! skip_this_one)
+	set_stat (data->file_name, &data->stat_info, current_stat_info,
+		  data->invert_permissions, data->permstatus, DIRTYPE);
+
       delayed_set_stat_head = data->next;
-      set_stat (data->file_name, &data->stat_info,
-		data->invert_permissions, data->permstatus, DIRTYPE);
       free (data);
     }
 }
