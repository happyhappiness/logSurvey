			oldrefname, newrefname, strerror(errno));
	if (!logmoved && log &&
	    rename(tmp_renamed_log.buf, sb_oldref.buf))
		error("unable to restore logfile %s from logs/"TMP_RENAMED_LOG": %s",
			oldrefname, strerror(errno));
	ret = 1;
 out: