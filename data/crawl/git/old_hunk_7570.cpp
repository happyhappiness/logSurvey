		return;
	}

	dump_marks_helper(f, 0, marks);
	if (ferror(f) || fclose(f))
		failure |= error("Unable to write marks file %s: %s",
			mark_file, strerror(errno));
	/*
	 * Since the lock file was fdopen()'ed and then fclose()'ed above,
	 * assign -1 to the lock file descriptor so that commit_lock_file()
	 * won't try to close() it.
	 */
	mark_lock.fd = -1;
	if (commit_lock_file(&mark_lock))
		failure |= error("Unable to write commit file %s: %s",
			mark_file, strerror(errno));
}

static int read_next_command(void)