			merge_msg.len)
			die("Could not write to %s", git_path("MERGE_MSG"));
		close(fd);
	}

	if (merge_was_ok) {
