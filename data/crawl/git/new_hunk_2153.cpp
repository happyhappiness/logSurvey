		if (argc == 1 && track == BRANCH_TRACK_OVERRIDE &&
		    !branch_existed && remote_tracking) {
			fprintf(stderr, _("\nIf you wanted to make '%s' track '%s', do this:\n\n"), head, branch->name);
			fprintf(stderr, "    git branch -d %s\n", branch->name);
			fprintf(stderr, "    git branch --set-upstream-to %s\n", branch->name);
		}

	} else