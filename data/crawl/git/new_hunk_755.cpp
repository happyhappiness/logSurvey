		die(_("No names found, cannot describe anything."));

	if (argc == 0) {
		if (broken) {
			struct child_process cp = CHILD_PROCESS_INIT;
			argv_array_pushv(&cp.args, diff_index_args);
			cp.git_cmd = 1;
			cp.no_stdin = 1;
			cp.no_stdout = 1;

			if (!dirty)
				dirty = "-dirty";

			switch (run_command(&cp)) {
			case 0:
				suffix = NULL;
				break;
			case 1:
				suffix = dirty;
				break;
			default:
				/* diff-index aborted abnormally */
				suffix = broken;
			}
		} else if (dirty) {
			static struct lock_file index_lock;
			int fd;

