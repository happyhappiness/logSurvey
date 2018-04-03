		len += sprintf(logrec + len - 1, "\t%.*s\n", msglen, msg) - 1;
	written = len <= maxlen ? write_in_full(logfd, logrec, len) : -1;
	free(logrec);
	if (close(logfd) != 0 || written != len)
		return error("Unable to append to %s", log_file);
	return 0;
}
