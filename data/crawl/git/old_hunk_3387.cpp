		}
	}

	if (log && safe_create_leading_directories(git_path("logs/%s", newrefname))) {
		error("unable to create directory for %s", newrefname);
		goto rollback;
	}

 retry:
	if (log && rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", newrefname))) {
		if (errno==EISDIR || errno==ENOTDIR) {
			/*
			 * rename(a, b) when b is an existing
			 * directory ought to result in ISDIR, but
			 * Solaris 5.8 gives ENOTDIR.  Sheesh.
			 */
			if (remove_empty_directories(git_path("logs/%s", newrefname))) {
				error("Directory not empty: logs/%s", newrefname);
				goto rollback;
			}
			goto retry;
		} else {
			error("unable to move logfile "TMP_RENAMED_LOG" to logs/%s: %s",
				newrefname, strerror(errno));
			goto rollback;
		}
	}
	logmoved = log;

	lock = lock_ref_sha1_basic(newrefname, NULL, 0, NULL);