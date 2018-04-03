
		if (keep_fd < 0) {
			if (errno != EEXIST)
				die_errno("cannot write keep file '%s'",
					  keep_name);
		} else {
			if (keep_msg_len > 0) {
				write_or_die(keep_fd, keep_msg, keep_msg_len);
				write_or_die(keep_fd, "\n", 1);
			}
			if (close(keep_fd) != 0)
				die_errno("cannot close written keep file '%s'",
				    keep_name);
			report = "keep";
		}
	}
