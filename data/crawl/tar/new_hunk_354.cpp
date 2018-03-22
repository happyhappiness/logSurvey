      umask (newdir_umask);	/* restore the kernel umask */
      current_umask = newdir_umask;
    }
}

/* If restoring permissions, restore the mode for FILE_NAME from
   information given in *STAT_INFO; otherwise invert the
   INVERT_PERMISSIONS bits from the file's current permissions.
   PERMSTATUS specifies the status of the file's permissions.
   TYPEFLAG specifies the type of the file.  */
static void
set_mode (char *file_name, struct stat *stat_info,
	  mode_t invert_permissions, enum permstatus permstatus,
	  char typeflag)
{
  mode_t mode;

  if (0 < same_permissions_option
      && permstatus != INTERDIR_PERMSTATUS)
    {
      mode = stat_info->st_mode;

      /* If we created the file and it has a usual mode, then its mode
	 is normally set correctly already.  But on many hosts, some
	 directories inherit the setgid bits from their parents, so we
	 we must set directories' modes explicitly.  */
      if (permstatus == ARCHIVED_PERMSTATUS
	  && ! (mode & ~ MODE_RWX)
	  && typeflag != DIRTYPE
	  && typeflag != GNUTYPE_DUMPDIR)
	return;
    }
  else if (! invert_permissions)
    return;
  else
    {
      /* We must inspect a directory's current permissions, since the
	 directory may have inherited its setgid bit from its parent.

	 INVERT_PERMISSIONS happens to be nonzero only for directories
	 that we created, so there's no point optimizing this code for
	 other cases.  */
      struct stat st;
      if (stat (file_name, &st) != 0)
	{
	  stat_error (file_name);
	  return;
	}
      mode = st.st_mode ^ invert_permissions;
    }

  if (chmod (file_name, mode) != 0)
    {
      int e = errno;
      ERROR ((0, e, _("%s: Cannot change mode to %04lo"),
	      quotearg_colon (file_name), (unsigned long) mode));
    }
}

/* Restore stat attributes (owner, group, mode and times) for
   FILE_NAME, using information given in *STAT_INFO.
   If not restoring permissions, invert the
   INVERT_PERMISSIONS bits from the file's current permissions.
   PERMSTATUS specifies the status of the file's permissions.
   TYPEFLAG specifies the type of the file.  */

/* FIXME: About proper restoration of symbolic link attributes, we still do
   not have it right.  Pretesters' reports tell us we need further study and
