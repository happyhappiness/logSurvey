		n = strlen(p);
	if (!n)
		die("Empty path component found in input");

	for (i = 0; i < t->entry_count; i++) {
		e = t->entries[i];
		if (e->name->str_len == n && !strncmp(p, e->name->str_dat, n)) {
			if (!slash1) {
				if (e->versions[1].mode == mode
						&& !hashcmp(e->versions[1].sha1, sha1))
					return 0;
				e->versions[1].mode = mode;
				hashcpy(e->versions[1].sha1, sha1);
				if (e->tree) {
					release_tree_content_recursive(e->tree);
					e->tree = NULL;
				}
				hashclr(root->versions[1].sha1);
				return 1;
			}
