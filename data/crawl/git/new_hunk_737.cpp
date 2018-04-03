	struct stat loginfo;
	int log = !lstat(git_path("logs/%s", oldrefname), &loginfo);
	struct strbuf err = STRBUF_INIT;
	int ret;

	if (log && S_ISLNK(loginfo.st_mode)) {
		ret = error("reflog for %s is a symlink", oldrefname);
		goto out;
	}

	if (!resolve_ref_unsafe(oldrefname, RESOLVE_REF_READING | RESOLVE_REF_NO_RECURSE,
				orig_sha1, &flag)) {
		ret = error("refname %s not found", oldrefname);
		goto out;
	}

	if (flag & REF_ISSYMREF) {
		ret = error("refname %s is a symbolic ref, renaming it is not supported",
			    oldrefname);
		goto out;
	}
	if (!rename_ref_available(oldrefname, newrefname)) {
		ret = 1;
		goto out;
	}

	if (log && rename(git_path("logs/%s", oldrefname), git_path(TMP_RENAMED_LOG))) {
		ret = error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
			    oldrefname, strerror(errno));
		goto out;
	}

	if (delete_ref(logmsg, oldrefname, orig_sha1, REF_NODEREF)) {
		error("unable to delete old %s", oldrefname);
