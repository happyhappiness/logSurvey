		exit(status);
}

static int grep_cache(struct grep_opt *opt, struct repository *repo,
		      const struct pathspec *pathspec, int cached);
static int grep_tree(struct grep_opt *opt, const struct pathspec *pathspec,
		     struct tree_desc *tree, struct strbuf *base, int tn_len,
		     int check_attr, struct repository *repo);

static int grep_submodule(struct grep_opt *opt, struct repository *superproject,
			  const struct pathspec *pathspec,
			  const struct object_id *oid,
			  const char *filename, const char *path)
{
	struct repository submodule;
	int hit;

	if (!is_submodule_active(superproject, path))
		return 0;

	if (repo_submodule_init(&submodule, superproject, path))
		return 0;

	repo_read_gitmodules(&submodule);

	/*
	 * NEEDSWORK: This adds the submodule's object directory to the list of
	 * alternates for the single in-memory object store.  This has some bad
	 * consequences for memory (processed objects will never be freed) and
	 * performance (this increases the number of pack files git has to pay
	 * attention to, to the sum of the number of pack files in all the
	 * repositories processed so far).  This can be removed once the object
	 * store is no longer global and instead is a member of the repository
	 * object.
	 */
	add_to_alternates_memory(submodule.objectdir);

	if (oid) {
		struct object *object;
		struct tree_desc tree;
		void *data;
		unsigned long size;
		struct strbuf base = STRBUF_INIT;

		object = parse_object_or_die(oid, oid_to_hex(oid));

		grep_read_lock();
		data = read_object_with_reference(object->oid.hash, tree_type,
						  &size, NULL);
		grep_read_unlock();

		if (!data)
			die(_("unable to read tree (%s)"), oid_to_hex(&object->oid));

		strbuf_addstr(&base, filename);
		strbuf_addch(&base, '/');

		init_tree_desc(&tree, data, size);
		hit = grep_tree(opt, pathspec, &tree, &base, base.len,
				object->type == OBJ_COMMIT, &submodule);
		strbuf_release(&base);
		free(data);
	} else {
		hit = grep_cache(opt, &submodule, pathspec, 1);
	}

	repo_clear(&submodule);
	return hit;
}

static int grep_cache(struct grep_opt *opt, struct repository *repo,
		      const struct pathspec *pathspec, int cached)
{
	int hit = 0;
	int nr;
	struct strbuf name = STRBUF_INIT;
	int name_base_len = 0;
	if (repo->submodule_prefix) {
		name_base_len = strlen(repo->submodule_prefix);
		strbuf_addstr(&name, repo->submodule_prefix);
	}

	repo_read_index(repo);

	for (nr = 0; nr < repo->index->cache_nr; nr++) {
		const struct cache_entry *ce = repo->index->cache[nr];
		strbuf_setlen(&name, name_base_len);
		strbuf_addstr(&name, ce->name);

