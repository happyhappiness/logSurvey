done:
	sigchain_pop(SIGPIPE);

	if (err) {
		error("initialization for external filter '%s' failed", cmd);
		kill_multi_file_filter(hashmap, entry);