			p = uq.buf;
		}
		read_next_command();
		parse_and_store_blob(&last_blob, sha1, 0);
	} else if (oe) {
		if (oe->type != OBJ_BLOB)
			die("Not a blob (actually a %s): %s",
				typename(oe->type), command_buf.buf);
	} else if (!is_null_sha1(sha1)) {
		enum object_type type = sha1_object_info(sha1, NULL);
		if (type < 0)
			die("Blob not found: %s", command_buf.buf);
		if (type != OBJ_BLOB)
			die("Not a blob (actually a %s): %s",
			    typename(type), command_buf.buf);
	}

	construct_path_with_fanout(sha1_to_hex(commit_sha1), *old_fanout, path);
	if (tree_content_remove(&b->branch_tree, path, NULL, 0))
		b->num_notes--;

	if (is_null_sha1(sha1))
		return; /* nothing to insert */

	b->num_notes++;
	new_fanout = convert_num_notes_to_fanout(b->num_notes);
	construct_path_with_fanout(sha1_to_hex(commit_sha1), new_fanout, path);
	tree_content_set(&b->branch_tree, path, sha1, S_IFREG | 0644, NULL);
}

static void file_change_deleteall(struct branch *b)
