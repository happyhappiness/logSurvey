				break;
		free_commit_list(bases);
		if (!ent) {
			error("denying non-fast-forward %s"
			      " (you should pull first)", name);
			return "non-fast-forward";
		}
	}
	if (run_update_hook(cmd)) {
