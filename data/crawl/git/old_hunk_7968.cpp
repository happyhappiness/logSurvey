	if (alias_string) {
		if (alias_string[0] == '!') {
			if (*argcp > 1) {
				int i, sz = PATH_MAX;
				char *s = xmalloc(sz), *new_alias = s;

				add_to_string(&s, &sz, alias_string, 0);
				free(alias_string);
				alias_string = new_alias;
				for (i = 1; i < *argcp &&
					!add_to_string(&s, &sz, " ", 0) &&
					!add_to_string(&s, &sz, (*argv)[i], 1)
					; i++)
					; /* do nothing */
				if (!sz)
					die("Too many or long arguments");
			}
			trace_printf("trace: alias to shell cmd: %s => %s\n",
				     alias_command, alias_string + 1);
