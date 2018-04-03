				l->key_sha1[19] = (unsigned char) len;
				type = PTR_TYPE_SUBTREE;
			}
			note_tree_insert(t, node, n, l, type,
					 combine_notes_concatenate);
		}
		continue;

