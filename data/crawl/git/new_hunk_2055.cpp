
	dump_marks_helper(f, 0, marks);
	if (commit_lock_file(&mark_lock)) {
		failure |= error_errno("Unable to write file %s",
				       export_marks_file);
		return;
	}
}