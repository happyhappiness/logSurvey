		OPT_END()
	};

	git_config(git_default_config, NULL);

	am_state_init(&state, git_path("rebase-apply"));
