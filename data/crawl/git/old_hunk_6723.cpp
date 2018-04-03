			    alias_string + 1, alias_command);
		}
		count = split_cmdline(alias_string, &new_argv);
		option_count = handle_options(&new_argv, &count, &envchanged);
		if (envchanged)
			die("alias '%s' changes environment variables\n"
