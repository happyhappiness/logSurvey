	die("Unknown command: %d", command);
}


static int do_pick_commit(enum todo_command command, struct commit *commit,
		struct replay_opts *opts)
