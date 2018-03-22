       if (symlink_flag)
 	{
 	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
-	    ERROR ((0, errno, _("%s: Cannot lchown to uid %d gid %d"),
-		    file_name, stat_info->st_uid, stat_info->st_gid));
+	    ERROR ((0, errno, _("%s: Cannot lchown to uid %lu gid %lu"),
+		    file_name,
+		    (unsigned long) stat_info->st_uid,
+		    (unsigned long) stat_info->st_gid));
 	}
       else
 	{
 	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
-	    ERROR ((0, errno, _("%s: Cannot chown to uid %d gid %d"),
-		    file_name, stat_info->st_uid, stat_info->st_gid));
+	    ERROR ((0, errno, _("%s: Cannot chown to uid %lu gid %lu"),
+		    file_name,
+		    (unsigned long) stat_info->st_uid,
+		    (unsigned long) stat_info->st_gid));
 	}
 
 #else /* not HAVE_LCHOWN */
