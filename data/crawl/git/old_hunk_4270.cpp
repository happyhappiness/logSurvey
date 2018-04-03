	return cp - buf;
}

int log_ref_setup(const char *ref_name, char *logfile, int bufsize)
{
	int logfd, oflags = O_APPEND | O_WRONLY;

	git_snpath(logfile, bufsize, "logs/%s", ref_name);
	if (log_all_ref_updates &&
	    (!prefixcmp(ref_name, "refs/heads/") ||
	     !prefixcmp(ref_name, "refs/remotes/") ||
	     !prefixcmp(ref_name, "refs/notes/") ||
	     !strcmp(ref_name, "HEAD"))) {
		if (safe_create_leading_directories(logfile) < 0)
			return error("unable to create directory for %s",
				     logfile);
