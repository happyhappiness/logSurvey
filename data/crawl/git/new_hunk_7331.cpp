	stop_progress(&progress);
}

static inline int call_unpack_fn(struct cache_entry **src, struct unpack_trees_options *o, int remove)
{
	int ret = o->fn(src, o, remove);
	if (ret > 0) {
		o->pos += ret;
		ret = 0;
	}
	return ret;
}

static int unpack_index_entry(struct cache_entry *ce, struct unpack_trees_options *o)
{
	struct cache_entry *src[5] = { ce, };
	if (ce_stage(ce)) {
		if (o->skip_unmerged) {
			o->pos++;
		} else {
			remove_entry(o->pos);
		}
		return 0;
	}
	return call_unpack_fn(src, o, o->pos);
}

int traverse_trees_recursive(int n, unsigned long dirmask, unsigned long df_conflicts, struct name_entry *names, struct traverse_info *info)
{
	int i;
	struct tree_desc t[3];
	struct traverse_info newinfo;
	struct name_entry *p;

	p = names;
	while (!p->mode)
		p++;

	newinfo = *info;
	newinfo.prev = info;
	newinfo.name = *p;
	newinfo.pathlen += tree_entry_len(p->path, p->sha1) + 1;
	newinfo.conflicts |= df_conflicts;

	for (i = 0; i < n; i++, dirmask >>= 1) {
		const unsigned char *sha1 = NULL;
		if (dirmask & 1)
			sha1 = names[i].sha1;
		fill_tree_descriptor(t+i, sha1);
	}
	traverse_trees(n, t, &newinfo);
	return 0;
}

/*
 * Compare the traverse-path to the cache entry without actually
 * having to generate the textual representation of the traverse
 * path.
 *
 * NOTE! This *only* compares up to the size of the traverse path
 * itself - the caller needs to do the final check for the cache
 * entry having more data at the end!
 */
static int do_compare_entry(const struct cache_entry *ce, const struct traverse_info *info, const struct name_entry *n)
{
	int len, pathlen, ce_len;
	const char *ce_name;

	if (info->prev) {
		int cmp = do_compare_entry(ce, info->prev, &info->name);
		if (cmp)
			return cmp;
	}
	pathlen = info->pathlen;
	ce_len = ce_namelen(ce);

	/* If ce_len < pathlen then we must have previously hit "name == directory" entry */
	if (ce_len < pathlen)
		return -1;

	ce_len -= pathlen;
	ce_name = ce->name + pathlen;

	len = tree_entry_len(n->path, n->sha1);
	return df_name_compare(ce_name, ce_len, S_IFREG, n->path, len, n->mode);
}

static int compare_entry(const struct cache_entry *ce, const struct traverse_info *info, const struct name_entry *n)
{
	int cmp = do_compare_entry(ce, info, n);
	if (cmp)
		return cmp;

	/*
	 * Even if the beginning compared identically, the ce should
	 * compare as bigger than a directory leading up to it!
	 */
	return ce_namelen(ce) > traverse_path_len(info, n);
}

static struct cache_entry *create_ce_entry(const struct traverse_info *info, const struct name_entry *n, int stage)
{
	int len = traverse_path_len(info, n);
	struct cache_entry *ce = xcalloc(1, cache_entry_size(len));

	ce->ce_mode = create_ce_mode(n->mode);
	ce->ce_flags = create_ce_flags(len, stage);
	hashcpy(ce->sha1, n->sha1);
	make_traverse_path(ce->name, info, n);

	return ce;
}

static int unpack_nondirectories(int n, unsigned long mask, unsigned long dirmask, struct cache_entry *src[5],
	const struct name_entry *names, const struct traverse_info *info, int remove)
{
	int i;
	struct unpack_trees_options *o = info->data;
	unsigned long conflicts;

	/* Do we have *only* directories? Nothing to do */
	if (mask == dirmask && !src[0])
		return 0;

	conflicts = info->conflicts;
	if (o->merge)
		conflicts >>= 1;
	conflicts |= dirmask;

	/*
	 * Ok, we've filled in up to any potential index entry in src[0],
	 * now do the rest.
	 */
	for (i = 0; i < n; i++) {
		int stage;
		unsigned int bit = 1ul << i;
		if (conflicts & bit) {
			src[i + o->merge] = o->df_conflict_entry;
			continue;
		}
		if (!(mask & bit))
			continue;
		if (!o->merge)
			stage = 0;
		else if (i + 1 < o->head_idx)
			stage = 1;
		else if (i + 1 > o->head_idx)
			stage = 3;
		else
			stage = 2;
		src[i + o->merge] = create_ce_entry(info, names + i, stage);
	}

	if (o->merge)
		return call_unpack_fn(src, o, remove);

	n += o->merge;
	remove_entry(remove);
	for (i = 0; i < n; i++)
		add_cache_entry(src[i], ADD_CACHE_OK_TO_ADD|ADD_CACHE_SKIP_DFCHECK);
	return 0;
}

static int unpack_callback(int n, unsigned long mask, unsigned long dirmask, struct name_entry *names, struct traverse_info *info)
{
	struct cache_entry *src[5] = { NULL, };
	struct unpack_trees_options *o = info->data;
	int remove = -1;
	const struct name_entry *p = names;

	/* Find first entry with a real name (we could use "mask" too) */
	while (!p->mode)
		p++;

	/* Are we supposed to look at the index too? */
	if (o->merge) {
		while (o->pos < active_nr) {
			struct cache_entry *ce = active_cache[o->pos];
			int cmp = compare_entry(ce, info, p);
			if (cmp < 0) {
				if (unpack_index_entry(ce, o) < 0)
					return -1;
				continue;
			}
			if (!cmp) {
				if (ce_stage(ce)) {
					/*
					 * If we skip unmerged index entries, we'll skip this
					 * entry *and* the tree entries associated with it!
					 */
					if (o->skip_unmerged)
						return mask;
					remove_entry(o->pos);
					continue;
				}
				src[0] = ce;
				remove = o->pos;
			}
			break;
		}
	}

	if (unpack_nondirectories(n, mask, dirmask, src, names, info, remove) < 0)
		return -1;

	/* Now handle any directories.. */
	if (dirmask) {
		unsigned long conflicts = mask & ~dirmask;
		if (o->merge) {
			conflicts <<= 1;
			if (src[0])
				conflicts |= 1;
		}
		traverse_trees_recursive(n, dirmask, conflicts, names, info);
		return mask;
	}

	return mask;
}

static int unpack_failed(struct unpack_trees_options *o, const char *message)
{
	if (!o->gently) {
		if (message)
			return error(message);
		return -1;
	}
	discard_cache();
	read_cache();
	return -1;
}

int unpack_trees(unsigned len, struct tree_desc *t, struct unpack_trees_options *o)
{
	static struct cache_entry *dfc;

	if (len > 4)
		die("unpack_trees takes at most four trees");
	memset(&state, 0, sizeof(state));
	state.base_dir = "";
	state.force = 1;
