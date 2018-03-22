	{
#if HAVE_LCHOWN
	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    chown_error_details (file_name,
				 stat_info->st_uid, stat_info->st_gid);
#endif
	}
      else
	{
	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    chown_error_details (file_name,
				 stat_info->st_uid, stat_info->st_gid);

	  /* On a few systems, and in particular, those allowing to give files
	     away, changing the owner or group destroys the suid or sgid bits.
