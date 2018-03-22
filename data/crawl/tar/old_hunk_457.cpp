      if (!symlink_flag)

	if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	  ERROR ((0, errno, _("%s: Cannot chown to uid %d gid %d"),
		  file_name, stat_info->st_uid, stat_info->st_gid));

#endif/* not HAVE_LCHOWN */

