				fprintf(stderr, "-c expects a configuration string\n" );
				usage(git_usage_string);
			}
			git_config_parse_parameter((*argv)[1]);
			(*argv)++;
			(*argc)--;
		} else {