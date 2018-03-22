   return did_something;		/* tell them to retry if we made one */
 }
 
-/*--------------------------------------------------------------------.
-| Unlink the destination, if we are supposed to do so.		      |
-| Return zero if extraction should not proceed.			      |
-`--------------------------------------------------------------------*/
+/* Prepare to extract a file.
+   Return zero if extraction should not proceed.  */
 
 static int
-unlink_destination (char const *file_name)
+prepare_to_extract (char const *file_name)
 {
-  if (unlink_first_option
+  if (to_stdout_option)
+    return 0;
+
+  if (old_files_option == UNLINK_FIRST_OLD_FILES
       && !remove_any_file (file_name, recursive_unlink_option)
       && errno != ENOENT)
     {
-      ERROR ((0, errno, _("Cannot remove %s"), file_name));
+      unlink_error (file_name);
       return 0;
     }
 
