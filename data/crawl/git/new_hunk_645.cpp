		code += 128;
	} else if (WIFEXITED(status)) {
		code = WEXITSTATUS(status);
	} else {
		error("waitpid is confused (%s)", argv0);
	}
