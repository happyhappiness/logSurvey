			die("Garbage after path in: %s", command_buf.buf);
		p = p_uq;
	}
	tree_content_remove(&b->branch_tree, p, NULL);
	free(p_uq);
}

static void file_change_r(struct branch *b)
{
	const char *s, *d;
	char *s_uq, *d_uq;
	const char *endp;
	struct tree_entry leaf;

	s = command_buf.buf + 2;
	s_uq = unquote_c_style(s, &endp);
	if (s_uq) {
		if (*endp != ' ')
			die("Missing space after source: %s", command_buf.buf);
	}
	else {
		endp = strchr(s, ' ');
		if (!endp)
			die("Missing space after source: %s", command_buf.buf);
		s_uq = xmalloc(endp - s + 1);
		memcpy(s_uq, s, endp - s);
		s_uq[endp - s] = 0;
	}
	s = s_uq;

	endp++;
	if (!*endp)
		die("Missing dest: %s", command_buf.buf);

	d = endp;
	d_uq = unquote_c_style(d, &endp);
	if (d_uq) {
		if (*endp)
			die("Garbage after dest in: %s", command_buf.buf);
		d = d_uq;
	}

	memset(&leaf, 0, sizeof(leaf));
	tree_content_remove(&b->branch_tree, s, &leaf);
	if (!leaf.versions[1].mode)
		die("Path %s not in branch", s);
	tree_content_set(&b->branch_tree, d,
		leaf.versions[1].sha1,
		leaf.versions[1].mode,
		leaf.tree);

	free(s_uq);
	free(d_uq);
}

static void file_change_deleteall(struct branch *b)
{
	release_tree_content_recursive(b->branch_tree.tree);
