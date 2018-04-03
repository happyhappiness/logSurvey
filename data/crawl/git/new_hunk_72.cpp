				*envchanged = 1;
		} else if (!strcmp(cmd, "-c")) {
			if (*argc < 2) {
				fprintf(stderr, _("-c expects a configuration string\n" ));
				usage(git_usage_string);
			}
			git_config_push_parameter((*argv)[1]);
