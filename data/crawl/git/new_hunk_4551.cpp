	args[i] = NULL;

	if (run_command_v_opt(args, RUN_GIT_CMD))
		die(_("read-tree failed"));
}

static void reset_hard(unsigned const char *sha1, int verbose)