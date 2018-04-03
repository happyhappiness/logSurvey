		}
	}
	if (!is_in_cmdlist(&main_cmds, name) && !is_in_cmdlist(&other_cmds, name)) {

		fprintf(stderr, "Could not find merge strategy '%s'.\n\n", name);
		list_commands("strategies", longest, &main_cmds, &other_cmds);
		exit(1);
	}
