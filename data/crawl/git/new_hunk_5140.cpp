		 * another repository.
		 */
	} else if (inline_data) {
		if (S_ISDIR(mode))
			die("Directories cannot be specified 'inline': %s",
				command_buf.buf);
		if (p != uq.buf) {
			strbuf_addstr(&uq, p);
			p = uq.buf;
		}
		read_next_command();
		parse_and_store_blob(&last_blob, sha1, 0);
	} else {
		enum object_type expected = S_ISDIR(mode) ?
						OBJ_TREE: OBJ_BLOB;
		enum object_type type = oe ? oe->type :
					sha1_object_info(sha1, NULL);
		if (type < 0)
			die("%s not found: %s",
					S_ISDIR(mode) ?  "Tree" : "Blob",
					command_buf.buf);
		if (type != expected)
			die("Not a %s (actually a %s): %s",
				typename(expected), typename(type),
				command_buf.buf);
	}

	tree_content_set(&b->branch_tree, p, sha1, mode, NULL);
