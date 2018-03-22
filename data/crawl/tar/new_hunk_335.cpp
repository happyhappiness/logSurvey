	  utimbuf.modtime = stat_info->st_mtime;

	  if (utime (file_name, &utimbuf) < 0)
	    utime_error (file_name);
	}

      /* Some systems allow non-root users to give files away.  Once this
