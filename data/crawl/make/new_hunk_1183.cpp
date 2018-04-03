
	    file_timestamp_sprintf (mtimebuf, mtime);
	    file_timestamp_sprintf (nowbuf, now);
            error (NILF, _("*** Warning: File `%s' has modification time in the future (%s > %s)"),
                   file->name, mtimebuf, nowbuf);
            clock_skew_detected = 1;
          }
