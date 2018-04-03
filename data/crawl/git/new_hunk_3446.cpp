	free(head_name_to_free);
	head_name = head_name_to_free = resolve_refdup("HEAD", sha1, 0, NULL);

	checked_connectivity = 1;
	for (cmd = commands; cmd; cmd = cmd->next) {
		if (cmd->error_string)
			continue;

		if (cmd->skip_update)
			continue;

		cmd->error_string = update(cmd, si);
		if (shallow_update && !cmd->error_string &&
		    si->shallow_ref[cmd->index]) {
			error("BUG: connectivity check has not been run on ref %s",
			      cmd->ref_name);
			checked_connectivity = 0;
		}
	}

	if (shallow_update) {
		if (!checked_connectivity)
			error("BUG: run 'git fsck' for safety.\n"
			      "If there are errors, try to remove "
			      "the reported refs above");
		if (alt_shallow_file && *alt_shallow_file)
			unlink(alt_shallow_file);
	}
}

