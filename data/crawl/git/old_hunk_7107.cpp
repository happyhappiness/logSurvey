	else
		die("Invalid cleanup mode %s", cleanup_arg);

	if (all && argc > 0)
		die("Paths with -a does not make sense.");
	else if (interactive && argc > 0)
