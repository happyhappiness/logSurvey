}

/**
 * Applies current patch with git-apply. Returns 0 on success, -1 otherwise.
 */
static int run_apply(const struct am_state *state)
{
	struct child_process cp = CHILD_PROCESS_INIT;

	cp.git_cmd = 1;

	argv_array_push(&cp.args, "apply");
	argv_array_push(&cp.args, "--index");
	argv_array_push(&cp.args, am_path(state, "patch"));

	if (run_command(&cp))
		return -1;

	/* Reload index as git-apply will have modified it. */
	discard_cache();
	read_cache();

	return 0;
}

