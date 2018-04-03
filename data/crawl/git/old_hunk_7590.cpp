	}

	dump_marks_helper(f, 0, marks);
	fclose(f);
	if (commit_lock_file(&mark_lock))
		failure |= error("Unable to write marks file %s: %s",
			mark_file, strerror(errno));
}

static int read_next_command(void)
