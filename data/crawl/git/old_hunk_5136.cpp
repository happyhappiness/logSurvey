	if (write_ref_sha1(lock, orig_sha1, logmsg))
		return error("unable to save current sha1 in %s", renamed_ref);

	if (log && rename(git_path("logs/%s", oldref), git_path("tmp-renamed-log")))
		return error("unable to move logfile logs/%s to tmp-renamed-log: %s",
			oldref, strerror(errno));

	if (delete_ref(oldref, orig_sha1, REF_NODEREF)) {