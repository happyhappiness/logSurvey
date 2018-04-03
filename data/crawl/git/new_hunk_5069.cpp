		}
		exit(cmd->exec(cmd->name, arg));
	}

	cd_to_homedir();
	if (split_cmdline(prog, &user_argv) != -1) {
		if (is_valid_cmd_name(user_argv[0])) {
			prog = make_cmd(user_argv[0]);
			user_argv[0] = prog;
			execv(user_argv[0], (char *const *) user_argv);
		}
		free(prog);
		free(user_argv);
		die("unrecognized command '%s'", argv[2]);
	} else {
		free(prog);
		die("invalid command format '%s'", argv[2]);
	}
}