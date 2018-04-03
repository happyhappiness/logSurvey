				write_or_die(keep_fd, keep_msg, keep_msg_len);
				write_or_die(keep_fd, "\n", 1);
			}
			close(keep_fd);
			report = "keep";
		}
	}
