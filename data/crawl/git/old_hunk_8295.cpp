			    alias_string + 1, alias_command);
		}
		count = split_cmdline(alias_string, &new_argv);
		option_count = handle_options(&new_argv, &count);
		memmove(new_argv - option_count, new_argv,
				count * sizeof(char *));
		new_argv -= option_count;
