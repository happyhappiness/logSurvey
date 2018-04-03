	return (struct tree *) obj;
}

/*
 * NOTE! Tree refs to external git repositories
 * (ie gitlinks) do not count as real references.
 *
 * You don't have to have those repositories
 * available at all, much less have the objects
 * accessible from the current repository.
 */
static void track_tree_refs(struct tree *item)
{
	int n_refs = 0, i;
	struct object_refs *refs;
	struct tree_desc desc;
	struct name_entry entry;

	/* Count how many entries there are.. */
	init_tree_desc(&desc, item->buffer, item->size);
	while (tree_entry(&desc, &entry)) {
		if (S_ISGITLINK(entry.mode))
			continue;
		n_refs++;
	}

	/* Allocate object refs and walk it again.. */
	i = 0;
	refs = alloc_object_refs(n_refs);
	init_tree_desc(&desc, item->buffer, item->size);
	while (tree_entry(&desc, &entry)) {
		struct object *obj;

		if (S_ISGITLINK(entry.mode))
			continue;
		if (S_ISDIR(entry.mode))
			obj = &lookup_tree(entry.sha1)->object;
		else if (S_ISREG(entry.mode) || S_ISLNK(entry.mode))
			obj = &lookup_blob(entry.sha1)->object;
		else {
			warning("in tree %s: entry %s has bad mode %.6o\n",
			     sha1_to_hex(item->object.sha1), entry.path, entry.mode);
			obj = lookup_unknown_object(entry.sha1);
		}
		refs->ref[i++] = obj;
	}
	set_object_refs(&item->object, refs);
}

int parse_tree_buffer(struct tree *item, void *buffer, unsigned long size)
{
	if (item->object.parsed)
