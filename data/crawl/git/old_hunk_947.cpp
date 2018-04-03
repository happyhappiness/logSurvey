	string_list_clear(submodules, 1);
}

int find_unpushed_submodules(unsigned char new_sha1[20],
		const char *remotes_name, struct string_list *needs_pushing)
{
	struct rev_info rev;
	struct commit *commit;
	const char *argv[] = {NULL, NULL, "--not", "NULL", NULL};
	int argc = ARRAY_SIZE(argv) - 1;
	char *sha1_copy;
	struct string_list submodules = STRING_LIST_INIT_DUP;
	struct string_list_item *submodule;

	struct strbuf remotes_arg = STRBUF_INIT;

	strbuf_addf(&remotes_arg, "--remotes=%s", remotes_name);
	init_revisions(&rev, NULL);
	sha1_copy = xstrdup(sha1_to_hex(new_sha1));
	argv[1] = sha1_copy;
	argv[3] = remotes_arg.buf;
	setup_revisions(argc, argv, &rev, NULL);
	if (prepare_revision_walk(&rev))
		die("revision walk setup failed");

	while ((commit = get_revision(&rev)) != NULL)
		find_unpushed_submodule_commits(commit, &submodules);

	reset_revision_walk();
	free(sha1_copy);
	strbuf_release(&remotes_arg);

	for_each_string_list_item(submodule, &submodules) {
		struct collect_submodule_from_sha1s_data data;