	return git_default_config(var, value, cb);
}


int cmd_apply(int argc, const char **argv, const char *unused_prefix)
{
	int i;
	int read_stdin = 1;
	int options = 0;
	int errs = 0;
	int is_not_gitdir;

	const char *whitespace_option = NULL;

	prefix = setup_git_directory_gently(&is_not_gitdir);
	prefix_length = prefix ? strlen(prefix) : 0;
	git_config(git_apply_config, NULL);
	if (apply_default_whitespace)
		parse_whitespace_option(apply_default_whitespace);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		char *end;
		int fd;

		if (!strcmp(arg, "-")) {
			errs |= apply_patch(0, "<stdin>", options);
			read_stdin = 0;
			continue;
		}
		if (!prefixcmp(arg, "--exclude=")) {
			add_name_limit(arg + 10, 1);
			continue;
		}
		if (!prefixcmp(arg, "--include=")) {
			add_name_limit(arg + 10, 0);
			has_include = 1;
			continue;
		}
		if (!prefixcmp(arg, "-p")) {
			p_value = atoi(arg + 2);
			p_value_known = 1;
			continue;
		}
		if (!strcmp(arg, "--no-add")) {
			no_add = 1;
			continue;
		}
		if (!strcmp(arg, "--stat")) {
			apply = 0;
			diffstat = 1;
			continue;
		}
		if (!strcmp(arg, "--allow-binary-replacement") ||
		    !strcmp(arg, "--binary")) {
			continue; /* now no-op */
		}
		if (!strcmp(arg, "--numstat")) {
			apply = 0;
			numstat = 1;
			continue;
		}
		if (!strcmp(arg, "--summary")) {
			apply = 0;
			summary = 1;
			continue;
		}
		if (!strcmp(arg, "--check")) {
			apply = 0;
			check = 1;
			continue;
		}
		if (!strcmp(arg, "--index")) {
			if (is_not_gitdir)
				die("--index outside a repository");
			check_index = 1;
			continue;
		}
		if (!strcmp(arg, "--cached")) {
			if (is_not_gitdir)
				die("--cached outside a repository");
			check_index = 1;
			cached = 1;
			continue;
		}
		if (!strcmp(arg, "--apply")) {
			apply = 1;
			continue;
		}
		if (!strcmp(arg, "--build-fake-ancestor")) {
			apply = 0;
			if (++i >= argc)
				die ("need a filename");
			fake_ancestor = argv[i];
			continue;
		}
		if (!strcmp(arg, "-z")) {
			line_termination = 0;
			continue;
		}
		if (!prefixcmp(arg, "-C")) {
			p_context = strtoul(arg + 2, &end, 0);
			if (*end != '\0')
				die("unrecognized context count '%s'", arg + 2);
			continue;
		}
		if (!prefixcmp(arg, "--whitespace=")) {
			whitespace_option = arg + 13;
			parse_whitespace_option(arg + 13);
			continue;
		}
		if (!strcmp(arg, "-R") || !strcmp(arg, "--reverse")) {
			apply_in_reverse = 1;
			continue;
		}
		if (!strcmp(arg, "--unidiff-zero")) {
			unidiff_zero = 1;
			continue;
		}
		if (!strcmp(arg, "--reject")) {
			apply = apply_with_reject = apply_verbosely = 1;
			continue;
		}
		if (!strcmp(arg, "-v") || !strcmp(arg, "--verbose")) {
			apply_verbosely = 1;
			continue;
		}
		if (!strcmp(arg, "--inaccurate-eof")) {
			options |= INACCURATE_EOF;
			continue;
		}
		if (!strcmp(arg, "--recount")) {
			options |= RECOUNT;
			continue;
		}
		if (!prefixcmp(arg, "--directory=")) {
			arg += strlen("--directory=");
			root_len = strlen(arg);
			if (root_len && arg[root_len - 1] != '/') {
				char *new_root;
				root = new_root = xmalloc(root_len + 2);
				strcpy(new_root, arg);
				strcpy(new_root + root_len++, "/");
			} else
				root = arg;
			continue;
		}
		if (0 < prefix_length)
			arg = prefix_filename(prefix, prefix_length, arg);
