     }
 }
 
-void
-sys_compare_uid_gid (struct stat *a, struct stat *b)
+bool
+sys_compare_uid (struct stat *a, struct stat *b)
 {
-  if (a->st_uid != b->st_uid)
-    report_difference (_("Uid differs"));
-  if (a->st_gid != b->st_gid)
-    report_difference (_("Gid differs"));
+  return a->st_uid == b->st_uid;
 }
 
-void
+bool
+sys_compare_gid (struct stat *a, struct stat *b)
+{
+  return a->st_gid == b->st_gid;
+}
+
+bool
 sys_compare_links (struct stat *link_data, struct stat *stat_data)
 {
-  if (stat_data->st_dev != link_data->st_dev
-      || stat_data->st_ino != link_data->st_ino)
-    {
-      report_difference (_("Not linked to %s"),
-			 quote (current_stat_info.link_name));
-    }
+  return stat_data->st_dev == link_data->st_dev
+         && stat_data->st_ino == link_data->st_ino;
 }
 
 int
