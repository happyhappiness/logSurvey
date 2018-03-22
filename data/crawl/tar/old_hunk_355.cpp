	  utimbuf.modtime = stat_info->st_mtime;

	  if (utime (file_name, &utimbuf) < 0)
	    ERROR ((0, errno,
		    _("%s: Could not change access and modification times"),
		    file_name));
	}

      /* Some systems allow non-root users to give files away.  Once this
	 done, it is not possible anymore to change file permissions, so we
	 have to set permissions prior to possibly giving files away.  */

      set_mode (file_name, stat_info);
    }

  /* If we are root, set the owner and group of the extracted file, so we
     extract as the original owner.  Or else, if we are running as a user,
     leave the owner and group as they are, so we extract as that user.  */

  if (0 < same_owner_option)
    {
      /* When lchown exists, it should be used to change the attributes of
	 the symbolic link itself.  In this case, a mere chown would change
	 the attributes of the file the symbolic link is pointing to, and
	 should be avoided.  */

      if (symlink_flag)
	{
#if HAVE_LCHOWN
	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    ERROR ((0, errno, _("%s: Cannot lchown to uid %lu gid %lu"),
		    file_name,
		    (unsigned long) stat_info->st_uid,
		    (unsigned long) stat_info->st_gid));
#endif
	}
      else
	{
	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
	    ERROR ((0, errno, _("%s: Cannot chown to uid %lu gid %lu"),
		    file_name,
		    (unsigned long) stat_info->st_uid,
		    (unsigned long) stat_info->st_gid));

	  /* On a few systems, and in particular, those allowing to give files
	     away, changing the owner or group destroys the suid or sgid bits.
	     So let's attempt setting these bits once more.  */
	  if (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
	    set_mode (file_name, stat_info);
	}
    }
}

/*-----------------------------------------------------------------------.
| After a file/link/symlink/directory creation has failed, see if it's	 |
| because some required directory was not present, and if so, create all |
