	  adjusted_mtime -= adjustment;
#endif

	/* If the file's time appears to be in the future, udpate our
	   concept of the present and try once more.  */
	if (now < adjusted_mtime
	    && (now = file_timestamp_now ()) < adjusted_mtime)
          {
	    char mtimebuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
	    char nowbuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];

	    file_timestamp_sprintf (mtimebuf, mtime);
	    file_timestamp_sprintf (nowbuf, now);
            error (NILF, _("*** Warning: File `%s' has modification time in the future (%s > %s)"),
                   file->name, mtimebuf, nowbuf);
            clock_skew_detected = 1;
          }
      }
  }
