       umask (newdir_umask);	/* restore the kernel umask */
       current_umask = newdir_umask;
     }
-
-  /* FIXME: Just make sure we can add files in directories we create.  Maybe
-     should we later remove permissions we are adding, here?  */
-  newdir_umask &= ~ MODE_WXUSR;
 }
 
-/*------------------------------------------------------------------.
-| Restore mode for FILE_NAME, from information given in STAT_INFO.  |
-`------------------------------------------------------------------*/
-
+/* If restoring permissions, restore the mode for FILE_NAME from
+   information given in *STAT_INFO; otherwise invert the
+   INVERT_PERMISSIONS bits from the file's current permissions.
+   PERMSTATUS specifies the status of the file's permissions.
+   TYPEFLAG specifies the type of the file.  */
 static void
-set_mode (char *file_name, struct stat *stat_info)
+set_mode (char *file_name, struct stat *stat_info,
+	  mode_t invert_permissions, enum permstatus permstatus,
+	  char typeflag)
 {
-  /* Do nothing unless we are restoring the original permissions.
-
-     We must force permission when -k and -U are not selected, because if the
-     file already existed, open or creat would save the permission bits from
-     the previously created file, ignoring the ones we specified.
-
-     But with -k or -U selected, we know *we* created this file, so the mode
-     bits were set by our open.  If the file has abnormal mode bits, we must
-     chmod since writing or chown has probably reset them.  If the file is
-     normal, we merely skip the chmod.  This works because we did umask (0)
-     when -p, so umask will have left the specified mode alone.  */
+  mode_t mode;
 
   if (0 < same_permissions_option
-      && ((!keep_old_files_option && !unlink_first_option)
-	  || (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX))))
-    if (chmod (file_name, ~current_umask & stat_info->st_mode) < 0)
-      ERROR ((0, errno, _("%s: Cannot change mode to %04lo"),
-	      file_name,
-	      (unsigned long) (~current_umask & stat_info->st_mode)));
+      && permstatus != INTERDIR_PERMSTATUS)
+    {
+      mode = stat_info->st_mode;
+
+      /* If we created the file and it has a usual mode, then its mode
+	 is normally set correctly already.  But on many hosts, some
+	 directories inherit the setgid bits from their parents, so we
+	 we must set directories' modes explicitly.  */
+      if (permstatus == ARCHIVED_PERMSTATUS
+	  && ! (mode & ~ MODE_RWX)
+	  && typeflag != DIRTYPE
+	  && typeflag != GNUTYPE_DUMPDIR)
+	return;
+    }
+  else if (! invert_permissions)
+    return;
+  else
+    {
+      /* We must inspect a directory's current permissions, since the
+	 directory may have inherited its setgid bit from its parent.
+
+	 INVERT_PERMISSIONS happens to be nonzero only for directories
+	 that we created, so there's no point optimizing this code for
+	 other cases.  */
+      struct stat st;
+      if (stat (file_name, &st) != 0)
+	{
+	  stat_error (file_name);
+	  return;
+	}
+      mode = st.st_mode ^ invert_permissions;
+    }
+
+  if (chmod (file_name, mode) != 0)
+    {
+      int e = errno;
+      ERROR ((0, e, _("%s: Cannot change mode to %04lo"),
+	      quotearg_colon (file_name), (unsigned long) mode));
+    }
 }
 
-/*----------------------------------------------------------------------.
-| Restore stat attributes (owner, group, mode and times) for FILE_NAME, |
-| using information given in STAT_INFO.  SYMLINK_FLAG is non-zero for a |
-| freshly restored symbolic link.				        |
-`----------------------------------------------------------------------*/
+/* Restore stat attributes (owner, group, mode and times) for
+   FILE_NAME, using information given in *STAT_INFO.
+   If not restoring permissions, invert the
+   INVERT_PERMISSIONS bits from the file's current permissions.
+   PERMSTATUS specifies the status of the file's permissions.
+   TYPEFLAG specifies the type of the file.  */
 
 /* FIXME: About proper restoration of symbolic link attributes, we still do
    not have it right.  Pretesters' reports tell us we need further study and
