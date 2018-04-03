	 * FAT filesystems round time to nearest even second(!). Just
	 * allow for any file (NTFS or FAT) to perhaps suffer from this
	 * braindamage.
	 *
	 * Apparently, this doesn't happen with the MS-DOS/DJGPP port,
	 * although MS-DOS and MS-Windows 3.X/9X also use FAT filesystems.
	 */
	if (mtime > now && (((mtime % 2) == 0) && ((mtime-1) > now)))
#else
        if (mtime > now)
#endif
          {
            error("*** Warning: File `%s' has modification time in the future",
                  file->name);
            clock_skew_detected = 1;
          }
      }
