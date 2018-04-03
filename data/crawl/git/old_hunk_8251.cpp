	git_config(git_alias_config);
	if (alias_string) {
		if (alias_string[0] == '!') {
			trace_printf("trace: alias to shell cmd: %s => %s\n",
				     alias_command, alias_string + 1);
			ret = system(alias_string + 1);