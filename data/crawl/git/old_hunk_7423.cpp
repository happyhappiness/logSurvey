			status |= error("%s: %s", strerror(errno),
					newlog_path);
			unlink(newlog_path);
		} else if (rename(newlog_path, log_file)) {
			status |= error("cannot rename %s to %s",
					newlog_path, log_file);
			unlink(newlog_path);
		}
	}
	free(newlog_path);
