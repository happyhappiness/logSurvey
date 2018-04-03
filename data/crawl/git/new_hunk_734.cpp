	int flag = 0, logmoved = 0;
	struct ref_lock *lock;
	struct stat loginfo;
	struct strbuf sb_oldref = STRBUF_INIT;
	struct strbuf sb_newref = STRBUF_INIT;
	struct strbuf tmp_renamed_log = STRBUF_INIT;
	int log, ret;
	struct strbuf err = STRBUF_INIT;

	strbuf_git_path(&sb_oldref, "logs/%s", oldrefname);
	strbuf_git_path(&sb_newref, "logs/%s", newrefname);
	strbuf_git_path(&tmp_renamed_log, TMP_RENAMED_LOG);

	log = !lstat(sb_oldref.buf, &loginfo);
	if (log && S_ISLNK(loginfo.st_mode)) {
		ret = error("reflog for %s is a symlink", oldrefname);
		goto out;
