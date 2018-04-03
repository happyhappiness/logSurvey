			add_interactive++;
	}
	if (add_interactive) {
		if (argc != 2)
			die("add --interactive does not take any parameters");
		exit(interactive_add());
	}

	git_config(git_add_config);
