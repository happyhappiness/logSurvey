	argv_array_push(&child.args, "apply");
	argv_array_push(&child.args, stash_sha1.buf);
	if (!run_command(&child))
		printf(_("Applied autostash."));
	else {
		struct child_process store = CHILD_PROCESS_INIT;
