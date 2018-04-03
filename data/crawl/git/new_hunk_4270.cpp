	return cp - buf;
}

int log_ref_setup(const char *refname, char *logfile, int bufsize)
{
	int logfd, oflags = O_APPEND | O_WRONLY;

	git_snpath(logfile, bufsize, "logs/%s", refname);
	if (log_all_ref_updates &&
	    (!prefixcmp(refname, "refs/heads/") ||
	     !prefixcmp(refname, "refs/remotes/") ||
	     !prefixcmp(refname, "refs/notes/") ||
	     !strcmp(refname, "HEAD"))) {
		if (safe_create_leading_directories(logfile) < 0)
			return error("unable to create directory for %s",
				     logfile);
