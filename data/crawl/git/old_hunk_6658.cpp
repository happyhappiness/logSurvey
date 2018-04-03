	struct stat loginfo;
	int log = !lstat(git_path("logs/%s", oldref), &loginfo);
	const char *symref = NULL;
	int is_symref = 0;

	if (log && S_ISLNK(loginfo.st_mode))
		return error("reflog for %s is a symlink", oldref);

	symref = resolve_ref(oldref, orig_sha1, 1, &flag);
	if (flag & REF_ISSYMREF)
		is_symref = 1;
	if (!symref)
		return error("refname %s not found", oldref);

