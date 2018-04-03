
	if (waiting < 0) {
		failed_errno = errno;
		error_errno("waitpid for %s failed", argv0);
	} else if (waiting != pid) {
		error("waitpid is confused (%s)", argv0);
	} else if (WIFSIGNALED(status)) {
