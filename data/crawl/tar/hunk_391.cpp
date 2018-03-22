 
       if (symlink_flag)
 	{
+#if HAVE_LCHOWN
 	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
 	    ERROR ((0, errno, _("%s: Cannot lchown to uid %lu gid %lu"),
 		    file_name,
 		    (unsigned long) stat_info->st_uid,
 		    (unsigned long) stat_info->st_gid));
+#endif
 	}
       else
 	{
