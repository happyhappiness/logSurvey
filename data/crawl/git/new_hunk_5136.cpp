	if (write_ref_sha1(lock, orig_sha1, logmsg))
		return error("unable to save current sha1 in %s", renamed_ref);

	if (log && rename(git_path("logs/%s", oldref), git_path(TMP_RENAMED_LOG)))
		return error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
			oldref, strerror(errno));

	if (delete_ref(oldref, orig_sha1, REF_NODEREF)) {
