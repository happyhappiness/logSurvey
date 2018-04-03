		return;

	if (hold_lock_file_for_update(&mark_lock, export_marks_file, 0) < 0) {
		failure |= error("Unable to write marks file %s: %s",
			export_marks_file, strerror(errno));
		return;
	}

