	 * FAT filesystems round time to nearest even second(!). Just
	 * allow for any file (NTFS or FAT) to perhaps suffer from this
	 * braindamage.
	 */
	if (mtime > now && (((mtime % 2) == 0) && ((mtime-1) > now)))
#else
#ifdef __MSDOS__
	/* Scrupulous testing indicates that some Windows
	   filesystems can set file times up to 3 sec into the future!  */
	if (mtime > now + 3)
#else
        if (mtime > now)
#endif
#endif
          {
            error("*** Warning: File `%s' has modification time in the future (%ld > %ld)",
                  file->name, mtime, now);
            clock_skew_detected = 1;
          }
      }
