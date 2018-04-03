		cb.newlog = fdopen_lock_file(&reflog_lock, "w");
		if (!cb.newlog) {
			error("cannot fdopen %s (%s)",
			      reflog_lock.filename.buf, strerror(errno));
			goto failure;
		}
	}
