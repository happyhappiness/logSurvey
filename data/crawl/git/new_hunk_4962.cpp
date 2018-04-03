			free(entry);
		else
			*p = SET_PTR_TYPE(entry, type);
		return 0;
	case PTR_TYPE_NOTE:
		switch (type) {
		case PTR_TYPE_NOTE:
			if (!hashcmp(l->key_sha1, entry->key_sha1)) {
				/* skip concatenation if l == entry */
				if (!hashcmp(l->val_sha1, entry->val_sha1))
					return 0;

				ret = combine_notes(l->val_sha1,
						    entry->val_sha1);
				if (!ret && is_null_sha1(l->val_sha1))
					note_tree_remove(t, tree, n, entry);
				free(entry);
				return ret;
			}
			break;
		case PTR_TYPE_SUBTREE:
