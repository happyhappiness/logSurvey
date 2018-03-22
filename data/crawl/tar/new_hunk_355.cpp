	  utimbuf.modtime = stat_info->st_mtime;

	  if (utime (file_name, &utimbuf) < 0)
	    {
	      int e = errno;
	      ERROR ((0, e,
		      _("%s: Cannot change access and modification times"),
		      quotearg_colon (file_name)));
	    }
	}

      /* Some systems allow non-root users to give files away.  Once this
	 done, it is not possible anymore to change file permissions, so we
	 have to set permissions prior to possibly giving files away.  */

      set_mode (file_name, stat_info,
		invert_permissions, permstatus, typeflag);
    }

  if (0 < same_owner_option && permstatus != INTERDIR_PERMSTATUS)
    {
      /* When lchown exists, it should be used to change the attributes of
	 the symbolic link itself.  In this case, a mere chown would change
	 the attributes of the file the symbolic link is pointing to, and
	 should be avoided.  */

      if (typeflag == SYMTYPE)
	{
#if HAVE_LCHOWN
	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    {
	      int e = errno;
	      ERROR ((0, e, _("%s: Cannot lchown to uid %lu gid %lu"),
		      quotearg_colon (file_name),
		      (unsigned long) stat_info->st_uid,
		      (unsigned long) stat_info->st_gid));
	    }
#endif
	}
      else
	{
	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    {
	      int e = errno;
	      ERROR ((0, e, _("%s: Cannot chown to uid %lu gid %lu"),
		      quotearg_colon (file_name),
		      (unsigned long) stat_info->st_uid,
		      (unsigned long) stat_info->st_gid));
	    }

	  /* On a few systems, and in particular, those allowing to give files
	     away, changing the owner or group destroys the suid or sgid bits.
	     So let's attempt setting these bits once more.  */
	  if (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
	    set_mode (file_name, stat_info,
		      invert_permissions, permstatus, typeflag);
	}
    }
}

/* Remember to restore stat attributes (owner, group, mode and times)
   for the directory FILE_NAME, using information given in *STAT_INFO,
   once we stop extracting files into that directory.
   If not restoring permissions, remember to invert the
   INVERT_PERMISSIONS bits from the file's current permissions.
   PERMSTATUS specifies the status of the file's permissions.  */
static void
delay_set_stat (char const *file_name, struct stat const *stat_info,
		mode_t invert_permissions, enum permstatus permstatus)
{
  size_t file_name_len = strlen (file_name);
  struct delayed_set_stat *data = xmalloc (sizeof *data + file_name_len);
  data->file_name_len = file_name_len;
  strcpy (data->file_name, file_name);
  data->invert_permissions = invert_permissions;
  data->permstatus = permstatus;
  data->stat_info = *stat_info;
  data->next = delayed_set_stat_head;
  delayed_set_stat_head = data;
}

/* Update the delayed_set_stat info for an intermediate directory
   created on the path to DIR_NAME.  The intermediate directory
   turned out to be the same as this directory, due to ".." or
   symbolic links.  *DIR_STAT_INFO is the status of the directory.  */
static void
repair_delayed_set_stat (char const *dir_name,
			 struct stat const *dir_stat_info)
{
  struct delayed_set_stat *data;
  for (data = delayed_set_stat_head;  data;  data = data->next)
    {
      struct stat st;
      if (stat (data->file_name, &st) != 0)
	{
	  stat_error (data->file_name);
	  return;
	}

      if (st.st_dev == dir_stat_info->st_dev
	  && st.st_ino == dir_stat_info->st_ino)
	{
	  data->stat_info = current_stat;
	  data->invert_permissions = (MODE_RWX
				      & (current_stat.st_mode ^ st.st_mode));
	  data->permstatus = ARCHIVED_PERMSTATUS;
	  return;
	}
    }

  ERROR ((0, 0, _("Unexpected inconsistency when making directory %s"),
	  quote (dir_name)));
}

/*-----------------------------------------------------------------------.
| After a file/link/symlink/directory creation has failed, see if it's	 |
| because some required directory was not present, and if so, create all |
