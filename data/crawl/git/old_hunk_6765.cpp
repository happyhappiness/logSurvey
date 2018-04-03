				cmd, argv[0]);
			exit(1);
		}
		help_unknown_cmd(cmd);
	}

	fprintf(stderr, "Failed to run command '%s': %s\n",
