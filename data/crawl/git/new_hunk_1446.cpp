			die_errno("git commit-tree: failed to read");
	}

	if (commit_tree(buffer.buf, buffer.len, tree_oid.hash, parents,
			commit_oid.hash, NULL, sign_commit)) {
		strbuf_release(&buffer);
		return 1;
	}

	printf("%s\n", oid_to_hex(&commit_oid));
	strbuf_release(&buffer);
	return 0;
}