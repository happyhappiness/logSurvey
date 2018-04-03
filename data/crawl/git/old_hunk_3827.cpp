	return fn(osha1, nsha1, sb->buf + 82, timestamp, tz, message, cb_data);
}

int for_each_recent_reflog_ent(const char *refname, each_reflog_ent_fn fn, long ofs, void *cb_data)
{
	FILE *logfp;
	struct strbuf sb = STRBUF_INIT;
	int ret = 0;

	logfp = fopen(git_path("logs/%s", refname), "r");
	if (!logfp)
		return -1;

	if (ofs) {
		struct stat statbuf;
		if (fstat(fileno(logfp), &statbuf) ||
		    statbuf.st_size < ofs ||
		    fseek(logfp, -ofs, SEEK_END) ||
		    strbuf_getwholeline(&sb, logfp, '\n')) {
			fclose(logfp);
			strbuf_release(&sb);
			return -1;
		}
	}

	while (!ret && !strbuf_getwholeline(&sb, logfp, '\n'))
		ret = show_one_reflog_ent(&sb, fn, cb_data);
	fclose(logfp);
	strbuf_release(&sb);
	return ret;
}

int for_each_reflog_ent(const char *refname, each_reflog_ent_fn fn, void *cb_data)
{
	return for_each_recent_reflog_ent(refname, fn, 0, cb_data);
}

/*
 * Call fn for each reflog in the namespace indicated by name.  name
 * must be empty or end with '/'.  Name will be used as a scratch
