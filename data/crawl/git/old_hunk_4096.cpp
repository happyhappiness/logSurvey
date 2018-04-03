{
	struct commit *commit;
	struct origin *origin;
	unsigned char head_sha1[20];
	struct strbuf buf = STRBUF_INIT;
	const char *ident;
	time_t now;
	int size, len;
	struct cache_entry *ce;
	unsigned mode;

	verify_working_tree_path(head_sha1, path);

	time(&now);
	commit = xcalloc(1, sizeof(*commit));
	commit->parents = xcalloc(1, sizeof(*commit->parents));
	commit->parents->item = lookup_commit_reference(head_sha1);
	commit->object.parsed = 1;
	commit->date = now;
	commit->object.type = OBJ_COMMIT;

	origin = make_origin(commit, path);

	if (!contents_from || strcmp("-", contents_from)) {
		struct stat st;
		const char *read_from;
