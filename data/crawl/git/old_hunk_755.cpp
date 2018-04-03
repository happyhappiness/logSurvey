		die(_("No names found, cannot describe anything."));

	if (argc == 0) {
		if (dirty) {
			static struct lock_file index_lock;
			int fd;

