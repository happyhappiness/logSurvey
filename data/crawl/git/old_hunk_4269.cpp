 */
#define TMP_RENAMED_LOG  "logs/refs/.tmp-renamed-log"

int rename_ref(const char *oldref, const char *newref, const char *logmsg)
{
	unsigned char sha1[20], orig_sha1[20];
	int flag = 0, logmoved = 0;
	struct ref_lock *lock;
	struct stat loginfo;
	int log = !lstat(git_path("logs/%s", oldref), &loginfo);
	const char *symref = NULL;

	if (log && S_ISLNK(loginfo.st_mode))
		return error("reflog for %s is a symlink", oldref);

	symref = resolve_ref(oldref, orig_sha1, 1, &flag);
	if (flag & REF_ISSYMREF)
		return error("refname %s is a symbolic ref, renaming it is not supported",
			oldref);
	if (!symref)
		return error("refname %s not found", oldref);

	if (!is_refname_available(newref, oldref, get_packed_refs(NULL), 0))
		return 1;

	if (!is_refname_available(newref, oldref, get_loose_refs(NULL), 0))
		return 1;

	if (log && rename(git_path("logs/%s", oldref), git_path(TMP_RENAMED_LOG)))
		return error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
			oldref, strerror(errno));

	if (delete_ref(oldref, orig_sha1, REF_NODEREF)) {
		error("unable to delete old %s", oldref);
		goto rollback;
	}

	if (!read_ref_full(newref, sha1, 1, &flag) &&
	    delete_ref(newref, sha1, REF_NODEREF)) {
		if (errno==EISDIR) {
			if (remove_empty_directories(git_path("%s", newref))) {
				error("Directory not empty: %s", newref);
				goto rollback;
			}
		} else {
			error("unable to delete existing %s", newref);
			goto rollback;
		}
	}

	if (log && safe_create_leading_directories(git_path("logs/%s", newref))) {
		error("unable to create directory for %s", newref);
		goto rollback;
	}

 retry:
	if (log && rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", newref))) {
		if (errno==EISDIR || errno==ENOTDIR) {
			/*
			 * rename(a, b) when b is an existing
			 * directory ought to result in ISDIR, but
			 * Solaris 5.8 gives ENOTDIR.  Sheesh.
			 */
			if (remove_empty_directories(git_path("logs/%s", newref))) {
				error("Directory not empty: logs/%s", newref);
				goto rollback;
			}
			goto retry;
		} else {
			error("unable to move logfile "TMP_RENAMED_LOG" to logs/%s: %s",
				newref, strerror(errno));
			goto rollback;
		}
	}
	logmoved = log;

	lock = lock_ref_sha1_basic(newref, NULL, 0, NULL);
	if (!lock) {
		error("unable to lock %s for update", newref);
		goto rollback;
	}
	lock->force_write = 1;
	hashcpy(lock->old_sha1, orig_sha1);
	if (write_ref_sha1(lock, orig_sha1, logmsg)) {
		error("unable to write current sha1 into %s", newref);
		goto rollback;
	}

	return 0;

 rollback:
	lock = lock_ref_sha1_basic(oldref, NULL, 0, NULL);
	if (!lock) {
		error("unable to lock %s for rollback", oldref);
		goto rollbacklog;
	}

	lock->force_write = 1;
	flag = log_all_ref_updates;
	log_all_ref_updates = 0;
	if (write_ref_sha1(lock, orig_sha1, NULL))
		error("unable to write current sha1 into %s", oldref);
	log_all_ref_updates = flag;

 rollbacklog:
	if (logmoved && rename(git_path("logs/%s", newref), git_path("logs/%s", oldref)))
		error("unable to restore logfile %s from %s: %s",
			oldref, newref, strerror(errno));
	if (!logmoved && log &&
	    rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", oldref)))
		error("unable to restore logfile %s from "TMP_RENAMED_LOG": %s",
			oldref, strerror(errno));

	return 1;
}
