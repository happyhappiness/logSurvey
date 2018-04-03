	if (depth)
		return -1;

	for (i = 0, ref = ref_map; ref; ref = ref->next)
		i++;
	if (!i)
		return 0;

	argv = xmalloc(sizeof(*argv) * (i + 6));
	i = 0;
	argv[i++] = xstrdup("rev-list");
	argv[i++] = xstrdup("--quiet");
	argv[i++] = xstrdup("--objects");
	for (ref = ref_map; ref; ref = ref->next)
		argv[i++] = xstrdup(sha1_to_hex(ref->old_sha1));
	argv[i++] = xstrdup("--not");
	argv[i++] = xstrdup("--all");
	argv[i++] = NULL;

	memset(&revlist, 0, sizeof(revlist));
	revlist.argv = (const char**)argv;
	revlist.git_cmd = 1;
	revlist.no_stdin = 1;
	revlist.no_stdout = 1;
	revlist.no_stderr = 1;
	err = run_command(&revlist);

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	return err;
}

static int fetch_refs(struct transport *transport, struct ref *ref_map)
