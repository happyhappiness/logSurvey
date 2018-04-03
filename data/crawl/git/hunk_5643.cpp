 		unsigned int n);
 
 /*
- * To find a leaf_node:
+ * Search the tree until the appropriate location for the given key is found:
  * 1. Start at the root node, with n = 0
- * 2. Use the nth nibble of the key as an index into a:
- *    - If a[n] is an int_node, recurse into that node and increment n
- *    - If a leaf_node with matching key, return leaf_node (assert note entry)
+ * 2. If a[0] at the current level is a matching subtree entry, unpack that
+ *    subtree entry and remove it; restart search at the current level.
+ * 3. Use the nth nibble of the key as an index into a:
+ *    - If a[n] is an int_node, recurse from #2 into that node and increment n
  *    - If a matching subtree entry, unpack that subtree entry (and remove it);
  *      restart search at the current level.
- *    - Otherwise, we end up at a NULL pointer, or a non-matching leaf_node.
- *      Backtrack out of the recursion, one level at a time and check a[0]:
- *      - If a[0] at the current level is a matching subtree entry, unpack that
- *        subtree entry (and remove it); restart search at the current level.
+ *    - Otherwise, we have found one of the following:
+ *      - a subtree entry which does not match the key
+ *      - a note entry which may or may not match the key
+ *      - an unused leaf node (NULL)
+ *      In any case, set *tree and *n, and return pointer to the tree location.
  */
-static struct leaf_node *note_tree_find(struct int_node *tree, unsigned char n,
-		const unsigned char *key_sha1)
+static void **note_tree_search(struct int_node **tree,
+		unsigned char *n, const unsigned char *key_sha1)
 {
 	struct leaf_node *l;
-	unsigned char i = GET_NIBBLE(n, key_sha1);
-	void *p = tree->a[i];
+	unsigned char i;
+	void *p = (*tree)->a[0];
 
+	if (GET_PTR_TYPE(p) == PTR_TYPE_SUBTREE) {
+		l = (struct leaf_node *) CLR_PTR_TYPE(p);
+		if (!SUBTREE_SHA1_PREFIXCMP(key_sha1, l->key_sha1)) {
+			/* unpack tree and resume search */
+			(*tree)->a[0] = NULL;
+			load_subtree(l, *tree, *n);
+			free(l);
+			return note_tree_search(tree, n, key_sha1);
+		}
+	}
+
+	i = GET_NIBBLE(*n, key_sha1);
+	p = (*tree)->a[i];
 	switch(GET_PTR_TYPE(p)) {
 	case PTR_TYPE_INTERNAL:
-		l = note_tree_find(CLR_PTR_TYPE(p), n + 1, key_sha1);
-		if (l)
-			return l;
-		break;
-	case PTR_TYPE_NOTE:
-		l = (struct leaf_node *) CLR_PTR_TYPE(p);
-		if (!hashcmp(key_sha1, l->key_sha1))
-			return l; /* return note object matching given key */
-		break;
+		*tree = CLR_PTR_TYPE(p);
+		(*n)++;
+		return note_tree_search(tree, n, key_sha1);
 	case PTR_TYPE_SUBTREE:
 		l = (struct leaf_node *) CLR_PTR_TYPE(p);
 		if (!SUBTREE_SHA1_PREFIXCMP(key_sha1, l->key_sha1)) {
 			/* unpack tree and resume search */
-			tree->a[i] = NULL;
-			load_subtree(l, tree, n);
+			(*tree)->a[i] = NULL;
+			load_subtree(l, *tree, *n);
 			free(l);
-			return note_tree_find(tree, n, key_sha1);
+			return note_tree_search(tree, n, key_sha1);
 		}
-		break;
-	case PTR_TYPE_NULL:
+		/* fall through */
 	default:
-		assert(!p);
-		break;
+		return &((*tree)->a[i]);
 	}
+}
 
-	/*
-	 * Did not find key at this (or any lower) level.
-	 * Check if there's a matching subtree entry in tree->a[0].
-	 * If so, unpack tree and resume search.
-	 */
-	p = tree->a[0];
-	if (GET_PTR_TYPE(p) != PTR_TYPE_SUBTREE)
-		return NULL;
-	l = (struct leaf_node *) CLR_PTR_TYPE(p);
-	if (!SUBTREE_SHA1_PREFIXCMP(key_sha1, l->key_sha1)) {
-		/* unpack tree and resume search */
-		tree->a[0] = NULL;
-		load_subtree(l, tree, n);
-		free(l);
-		return note_tree_find(tree, n, key_sha1);
+/*
+ * To find a leaf_node:
+ * Search to the tree location appropriate for the given key:
+ * If a note entry with matching key, return the note entry, else return NULL.
+ */
+static struct leaf_node *note_tree_find(struct int_node *tree, unsigned char n,
+		const unsigned char *key_sha1)
+{
+	void **p = note_tree_search(&tree, &n, key_sha1);
+	if (GET_PTR_TYPE(*p) == PTR_TYPE_NOTE) {
+		struct leaf_node *l = (struct leaf_node *) CLR_PTR_TYPE(*p);
+		if (!hashcmp(key_sha1, l->key_sha1))
+			return l;
 	}
 	return NULL;
 }
 
+/* Create a new blob object by concatenating the two given blob objects */
+static int concatenate_notes(unsigned char *cur_sha1,
+		const unsigned char *new_sha1)
+{
+	char *cur_msg, *new_msg, *buf;
+	unsigned long cur_len, new_len, buf_len;
+	enum object_type cur_type, new_type;
+	int ret;
+
+	/* read in both note blob objects */
+	new_msg = read_sha1_file(new_sha1, &new_type, &new_len);
+	if (!new_msg || !new_len || new_type != OBJ_BLOB) {
+		free(new_msg);
+		return 0;
+	}
+	cur_msg = read_sha1_file(cur_sha1, &cur_type, &cur_len);
+	if (!cur_msg || !cur_len || cur_type != OBJ_BLOB) {
+		free(cur_msg);
+		free(new_msg);
+		hashcpy(cur_sha1, new_sha1);
+		return 0;
+	}
+
+	/* we will separate the notes by a newline anyway */
+	if (cur_msg[cur_len - 1] == '\n')
+		cur_len--;
+
+	/* concatenate cur_msg and new_msg into buf */
+	buf_len = cur_len + 1 + new_len;
+	buf = (char *) xmalloc(buf_len);
+	memcpy(buf, cur_msg, cur_len);
+	buf[cur_len] = '\n';
+	memcpy(buf + cur_len + 1, new_msg, new_len);
+
+	free(cur_msg);
+	free(new_msg);
+
+	/* create a new blob object from buf */
+	ret = write_sha1_file(buf, buf_len, "blob", cur_sha1);
+	free(buf);
+	return ret;
+}
+
 /*
  * To insert a leaf_node:
- * 1. Start at the root node, with n = 0
- * 2. Use the nth nibble of the key as an index into a:
- *    - If a[n] is NULL, store the tweaked pointer directly into a[n]
- *    - If a[n] is an int_node, recurse into that node and increment n
- *    - If a[n] is a leaf_node:
- *      1. Check if they're equal, and handle that (abort? overwrite?)
- *      2. Create a new int_node, and store both leaf_nodes there
- *      3. Store the new int_node into a[n].
+ * Search to the tree location appropriate for the given leaf_node's key:
+ * - If location is unused (NULL), store the tweaked pointer directly there
+ * - If location holds a note entry that matches the note-to-be-inserted, then
+ *   concatenate the two notes.
+ * - If location holds a note entry that matches the subtree-to-be-inserted,
+ *   then unpack the subtree-to-be-inserted into the location.
+ * - If location holds a matching subtree entry, unpack the subtree at that
+ *   location, and restart the insert operation from that level.
+ * - Else, create a new int_node, holding both the node-at-location and the
+ *   node-to-be-inserted, and store the new int_node into the location.
  */
-static int note_tree_insert(struct int_node *tree, unsigned char n,
-		const struct leaf_node *entry, unsigned char type)
+static void note_tree_insert(struct int_node *tree, unsigned char n,
+		struct leaf_node *entry, unsigned char type)
 {
 	struct int_node *new_node;
-	const struct leaf_node *l;
-	int ret;
-	unsigned char i = GET_NIBBLE(n, entry->key_sha1);
-	void *p = tree->a[i];
-	assert(GET_PTR_TYPE(entry) == PTR_TYPE_NULL);
-	switch(GET_PTR_TYPE(p)) {
+	struct leaf_node *l;
+	void **p = note_tree_search(&tree, &n, entry->key_sha1);
+
+	assert(GET_PTR_TYPE(entry) == 0); /* no type bits set */
+	l = (struct leaf_node *) CLR_PTR_TYPE(*p);
+	switch(GET_PTR_TYPE(*p)) {
 	case PTR_TYPE_NULL:
-		assert(!p);
-		tree->a[i] = SET_PTR_TYPE(entry, type);
-		return 0;
-	case PTR_TYPE_INTERNAL:
-		return note_tree_insert(CLR_PTR_TYPE(p), n + 1, entry, type);
-	default:
-		assert(GET_PTR_TYPE(p) == PTR_TYPE_NOTE ||
-			GET_PTR_TYPE(p) == PTR_TYPE_SUBTREE);
-		l = (const struct leaf_node *) CLR_PTR_TYPE(p);
-		if (!hashcmp(entry->key_sha1, l->key_sha1))
-			return -1; /* abort insert on matching key */
-		new_node = (struct int_node *)
-			xcalloc(sizeof(struct int_node), 1);
-		ret = note_tree_insert(new_node, n + 1,
-			CLR_PTR_TYPE(p), GET_PTR_TYPE(p));
-		if (ret) {
-			free(new_node);
-			return -1;
+		assert(!*p);
+		*p = SET_PTR_TYPE(entry, type);
+		return;
+	case PTR_TYPE_NOTE:
+		switch (type) {
+		case PTR_TYPE_NOTE:
+			if (!hashcmp(l->key_sha1, entry->key_sha1)) {
+				/* skip concatenation if l == entry */
+				if (!hashcmp(l->val_sha1, entry->val_sha1))
+					return;
+
+				if (concatenate_notes(l->val_sha1,
+						entry->val_sha1))
+					die("failed to concatenate note %s "
+					    "into note %s for commit %s",
+					    sha1_to_hex(entry->val_sha1),
+					    sha1_to_hex(l->val_sha1),
+					    sha1_to_hex(l->key_sha1));
+				free(entry);
+				return;
+			}
+			break;
+		case PTR_TYPE_SUBTREE:
+			if (!SUBTREE_SHA1_PREFIXCMP(l->key_sha1,
+						    entry->key_sha1)) {
+				/* unpack 'entry' */
+				load_subtree(entry, tree, n);
+				free(entry);
+				return;
+			}
+			break;
+		}
+		break;
+	case PTR_TYPE_SUBTREE:
+		if (!SUBTREE_SHA1_PREFIXCMP(entry->key_sha1, l->key_sha1)) {
+			/* unpack 'l' and restart insert */
+			*p = NULL;
+			load_subtree(l, tree, n);
+			free(l);
+			note_tree_insert(tree, n, entry, type);
+			return;
 		}
-		tree->a[i] = SET_PTR_TYPE(new_node, PTR_TYPE_INTERNAL);
-		return note_tree_insert(new_node, n + 1, entry, type);
+		break;
 	}
+
+	/* non-matching leaf_node */
+	assert(GET_PTR_TYPE(*p) == PTR_TYPE_NOTE ||
+	       GET_PTR_TYPE(*p) == PTR_TYPE_SUBTREE);
+	new_node = (struct int_node *) xcalloc(sizeof(struct int_node), 1);
+	note_tree_insert(new_node, n + 1, l, GET_PTR_TYPE(*p));
+	*p = SET_PTR_TYPE(new_node, PTR_TYPE_INTERNAL);
+	note_tree_insert(new_node, n + 1, entry, type);
 }
 
 /* Free the entire notes data contained in the given tree */
