 }
 
 /*--------------------------------------------------------------------.
+| Unlink the destination, if we are supposed to do so.		      |
+| Return zero if extraction should not proceed.			      |
+`--------------------------------------------------------------------*/
+
+static int
+unlink_destination (char const *file_name)
+{
+  if (unlink_first_option
+      && !remove_any_file (file_name, recursive_unlink_option)
+      && errno != ENOENT)
+    {
+      ERROR ((0, errno, _("Cannot remove %s"), file_name));
+      return 0;
+    }
+
+  return 1;
+}
+
+/*--------------------------------------------------------------------.
 | Attempt repairing what went wrong with the extraction.  Delete an   |
 | already existing file or create missing intermediate directories.   |
 | Return nonzero if we somewhat increased our chances at a successful |
