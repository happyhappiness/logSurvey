		unsigned int n);

/*
 * To find a leaf_node:
 * 1. Start at the root node, with n = 0
 * 2. Use the nth nibble of the key as an index into a:
 *    - If a[n] is an int_node, recurse into that node and increment n
 *    - If a leaf_node with matching key, return leaf_node (assert note entry)
 *    - If a matching subtree entry, unpack that subtree entry (and remove it);
 *      restart search at the current level.
 *    - Otherwise, we end up at a NULL pointer, or a non-matching leaf_node.
 *      Backtrack out of the recursion, one level at a time and check a[0]:
 *      - If a[0] at the current level is a matching subtree entry, unpack that
 *        subtree entry (and remove it); restart search at the current level.
 */
static struct leaf_node *note_tree_find(struct int_node *tree, unsigned char n,
		const unsigned char *key_sha1)
{
	struct leaf_node *l;
	unsigned char i = GET_NIBBLE(n, key_sha1);
	void *p = tree->a[i];

	switch(GET_PTR_TYPE(p)) {
	case PTR_TYPE_INTERNAL:
		l = note_tree_find(CLR_PTR_TYPE(p), n + 1, key_sha1);
		if (l)
			return l;
		break;
	case PTR_TYPE_NOTE:
		l = (struct leaf_node *) CLR_PTR_TYPE(p);
		if (!hashcmp(key_sha1, l->key_sha1))
			return l; /* return note object matching given key */
		break;
	case PTR_TYPE_SUBTREE:
		l = (struct leaf_node *) CLR_PTR_TYPE(p);
		if (!SUBTREE_SHA1_PREFIXCMP(key_sha1, l->key_sha1)) {
			/* unpack tree and resume search */
			tree->a[i] = NULL;
			load_subtree(l, tree, n);
			free(l);
			return note_tree_find(tree, n, key_sha1);
		}
		break;
	case PTR_TYPE_NULL:
	default:
		assert(!p);
		break;
	}

	/*
	 * Did not find key at this (or any lower) level.
	 * Check if there's a matching subtree entry in tree->a[0].
	 * If so, unpack tree and resume search.
	 */
	p = tree->a[0];
	if (GET_PTR_TYPE(p) != PTR_TYPE_SUBTREE)
		return NULL;
	l = (struct leaf_node *) CLR_PTR_TYPE(p);
	if (!SUBTREE_SHA1_PREFIXCMP(key_sha1, l->key_sha1)) {
		/* unpack tree and resume search */
		tree->a[0] = NULL;
		load_subtree(l, tree, n);
		free(l);
		return note_tree_find(tree, n, key_sha1);
	}
	return NULL;
}

/*
 * To insert a leaf_node:
 * 1. Start at the root node, with n = 0
 * 2. Use the nth nibble of the key as an index into a:
 *    - If a[n] is NULL, store the tweaked pointer directly into a[n]
 *    - If a[n] is an int_node, recurse into that node and increment n
 *    - If a[n] is a leaf_node:
 *      1. Check if they're equal, and handle that (abort? overwrite?)
 *      2. Create a new int_node, and store both leaf_nodes there
 *      3. Store the new int_node into a[n].
 */
static int note_tree_insert(struct int_node *tree, unsigned char n,
		const struct leaf_node *entry, unsigned char type)
{
	struct int_node *new_node;
	const struct leaf_node *l;
	int ret;
	unsigned char i = GET_NIBBLE(n, entry->key_sha1);
	void *p = tree->a[i];
	assert(GET_PTR_TYPE(entry) == PTR_TYPE_NULL);
	switch(GET_PTR_TYPE(p)) {
	case PTR_TYPE_NULL:
		assert(!p);
		tree->a[i] = SET_PTR_TYPE(entry, type);
		return 0;
	case PTR_TYPE_INTERNAL:
		return note_tree_insert(CLR_PTR_TYPE(p), n + 1, entry, type);
	default:
		assert(GET_PTR_TYPE(p) == PTR_TYPE_NOTE ||
			GET_PTR_TYPE(p) == PTR_TYPE_SUBTREE);
		l = (const struct leaf_node *) CLR_PTR_TYPE(p);
		if (!hashcmp(entry->key_sha1, l->key_sha1))
			return -1; /* abort insert on matching key */
		new_node = (struct int_node *)
			xcalloc(sizeof(struct int_node), 1);
		ret = note_tree_insert(new_node, n + 1,
			CLR_PTR_TYPE(p), GET_PTR_TYPE(p));
		if (ret) {
			free(new_node);
			return -1;
		}
		tree->a[i] = SET_PTR_TYPE(new_node, PTR_TYPE_INTERNAL);
		return note_tree_insert(new_node, n + 1, entry, type);
	}
}

/* Free the entire notes data contained in the given tree */
