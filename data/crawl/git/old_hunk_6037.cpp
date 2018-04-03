	return run_command_v_opt(argv_show_branch, RUN_GIT_CMD);
}

/*
 * We use the convention that exiting with an exit code 10 means that
 * the bisection process finished successfully.