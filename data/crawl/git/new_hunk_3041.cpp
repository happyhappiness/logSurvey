
		if (errno == EISDIR) {
			if (remove_empty_directories(logfile)) {
				strbuf_addf(err, "There are still logs under "
					    "'%s'", logfile);
				return -1;
			}
			logfd = open(logfile, oflags, 0666);
		}

		if (logfd < 0) {
			strbuf_addf(err, "unable to append to %s: %s",
				    logfile, strerror(errno));
			return -1;
		}
	}
