	if (write_shallow_commits(&sb, 0, extra)) {
		if (write_in_full(fd, sb.buf, sb.len) != sb.len)
			die_errno("failed to write to %s",
				  shallow_lock->filename.buf);
		*alternate_shallow_file = shallow_lock->filename.buf;
	} else
		/*
		 * is_repository_shallow() sees empty string as "no