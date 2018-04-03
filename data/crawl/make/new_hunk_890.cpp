	    if (adjusted_now < adjusted_mtime)
	      {
#ifdef NO_FLOAT
		error (NILF, _("Warning: File `%s' has modification time in the future"),
                       file->name);
#else
		double from_now =
		  (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
		   + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
		      / 1e9));
		error (NILF, _("Warning: File `%s' has modification time %.2g s in the future"),
		       file->name, from_now);
#endif
		clock_skew_detected = 1;
