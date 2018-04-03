{
	struct commit *commit;
	struct origin *origin;
	struct commit_list **parent_tail, *parent;
	unsigned char head_sha1[20];
	struct strbuf buf = STRBUF_INIT;
	const char *ident;
	time_t now;
	int size, len;
	struct cache_entry *ce;
	unsigned mode;
	struct strbuf msg = STRBUF_INIT;

	time(&now);
	commit = xcalloc(1, sizeof(*commit));
	commit->object.parsed = 1;
	commit->date = now;
	commit->object.type = OBJ_COMMIT;
	parent_tail = &commit->parents;

	if (!resolve_ref_unsafe("HEAD", head_sha1, 1, NULL))
		die("no such ref: HEAD");

	parent_tail = append_parent(parent_tail, head_sha1);
	append_merge_parents(parent_tail);
	verify_working_tree_path(commit, path);

	origin = make_origin(commit, path);

	ident = fmt_ident("Not Committed Yet", "not.committed.yet", NULL, 0);
	strbuf_addstr(&msg, "tree 0000000000000000000000000000000000000000\n");
	for (parent = commit->parents; parent; parent = parent->next)
		strbuf_addf(&msg, "parent %s\n",
			    sha1_to_hex(parent->item->object.sha1));
	strbuf_addf(&msg,
		    "author %s\n"
		    "committer %s\n\n"
		    "Version of %s from %s\n",
		    ident, ident, path,
		    (!contents_from ? path :
		     (!strcmp(contents_from, "-") ? "standard input" : contents_from)));
	commit->buffer = strbuf_detach(&msg, NULL);

	if (!contents_from || strcmp("-", contents_from)) {
		struct stat st;
		const char *read_from;
