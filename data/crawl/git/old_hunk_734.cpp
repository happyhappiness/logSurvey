	int flag = 0, logmoved = 0;
	struct ref_lock *lock;
	struct stat loginfo;
	int log = !lstat(git_path("logs/%s", oldrefname), &loginfo);
	struct strbuf err = STRBUF_INIT;
	int ret;

	if (log && S_ISLNK(loginfo.st_mode)) {
		ret = error("reflog for %s is a symlink", oldrefname);
		goto out;
