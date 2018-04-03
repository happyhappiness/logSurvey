	}

	if (strbuf_read(&buffer, 0, 0) < 0)
		die_errno("git commit-tree: failed to read");

	if (!commit_tree(buffer.buf, tree_sha1, parents, commit_sha1, NULL)) {
		printf("%s\n", sha1_to_hex(commit_sha1));
