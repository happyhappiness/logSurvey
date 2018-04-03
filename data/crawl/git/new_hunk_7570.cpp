		return;
	}

	/*
	 * Since the lock file was fdopen()'ed, it should not be close()'ed.
	 * Assign -1 to the lock file descriptor so that commit_lock_file()
	 * won't try to close() it.
	 */
	mark_lock.fd = -1;

	dump_marks_helper(f, 0, marks);
	if (ferror(f) || fclose(f)) {
		rollback_lock_file(&mark_lock);
		failure |= error("Unable to write marks file %s: %s",
			mark_file, strerror(errno));
		return;
	}

	if (commit_lock_file(&mark_lock)) {
		rollback_lock_file(&mark_lock);
		failure |= error("Unable to commit marks file %s: %s",
			mark_file, strerror(errno));
		return;
	}
}

static int read_next_command(void)