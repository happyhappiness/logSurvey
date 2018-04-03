	log_all_ref_updates = flag;

 rollbacklog:
	if (logmoved && rename(sb_newref.buf, sb_oldref.buf))
		error("unable to restore logfile %s from %s: %s",
			oldrefname, newrefname, strerror(errno));
	if (!logmoved && log &&
	    rename(tmp_renamed_log.buf, sb_oldref.buf))
		error("unable to restore logfile %s from "TMP_RENAMED_LOG": %s",
			oldrefname, strerror(errno));
	ret = 1;
 out:
	strbuf_release(&sb_newref);
	strbuf_release(&sb_oldref);
	strbuf_release(&tmp_renamed_log);

	return ret;
}

