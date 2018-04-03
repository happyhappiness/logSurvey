
		if (errno == EISDIR) {
			if (remove_empty_directories(logfile)) {
				int save_errno = errno;
				error("There are still logs under '%s'",
				      logfile);
				errno = save_errno;
				return -1;
			}
			logfd = open(logfile, oflags, 0666);
		}

		if (logfd < 0) {
			int save_errno = errno;
			error("Unable to append to %s: %s", logfile,
			      strerror(errno));
			errno = save_errno;
			return -1;
		}
	}
