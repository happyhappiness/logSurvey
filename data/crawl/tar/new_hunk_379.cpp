	    {
	      struct stat final_stat;
	      if (fstat (f, &final_stat) != 0)
		stat_error (p);
	      else if (final_stat.st_ctime != original_ctime)
		ERROR ((0, 0, _("File %s changed as we read it"), quote (p)));
	      if (close (f) != 0)
		close_error (p);
	      if (atime_preserve_option)
		utime (p, &restore_times);
	    }
	  if (remove_files_option)
	    {
	      if (unlink (p) == -1)
		unlink_error (p);
	    }
	  return;

