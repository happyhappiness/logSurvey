		fsync_or_die(output_fd, curr_pack_name);
		err = close(output_fd);
		if (err)
			die_errno("error while closing pack file");
	}

	if (keep_msg) {
