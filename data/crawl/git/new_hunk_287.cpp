		 * If object SHA1 is incomplete (len < 20), and current
		 * component consists of 2 hex chars, assume note subtree
		 */
		type = PTR_TYPE_NOTE;
		l = (struct leaf_node *)
			xcalloc(1, sizeof(struct leaf_node));
		oidcpy(&l->key_oid, &object_oid);
		oidcpy(&l->val_oid, entry.oid);
		if (len < GIT_SHA1_RAWSZ) {
			if (!S_ISDIR(entry.mode) || path_len != 2)
				goto handle_non_note; /* not subtree */
			l->key_oid.hash[KEY_INDEX] = (unsigned char) len;
			type = PTR_TYPE_SUBTREE;
		}
		if (note_tree_insert(t, node, n, l, type,
				     combine_notes_concatenate))
			die("Failed to load %s %s into notes tree "
			    "from %s",
			    type == PTR_TYPE_NOTE ? "note" : "subtree",
			    oid_to_hex(&l->key_oid), t->ref);

		continue;

handle_non_note: