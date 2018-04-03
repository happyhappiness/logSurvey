	} else if (waiting != pid) {
		error("waitpid is confused (%s)", argv0);
	} else if (WIFSIGNALED(status)) {
		error("%s died of signal", argv0);
	} else if (WIFEXITED(status)) {
		code = WEXITSTATUS(status);
		/*