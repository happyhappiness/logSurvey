	return parse_reuse_arg(opt, arg, unset);
}

int commit_notes(struct notes_tree *t, const char *msg)
{
	struct commit_list *parent;
	unsigned char tree_sha1[20], prev_commit[20], new_commit[20];
	struct strbuf buf = STRBUF_INIT;

	if (!t)
		t = &default_notes_tree;
	if (!t->initialized || !t->ref || !*t->ref)
		die("Cannot commit uninitialized/unreferenced notes tree");
	if (!t->dirty)
		return 0; /* don't have to commit an unchanged tree */

	/* Prepare commit message and reflog message */
	strbuf_addstr(&buf, "notes: "); /* commit message starts at index 7 */
	strbuf_addstr(&buf, msg);
	if (buf.buf[buf.len - 1] != '\n')
		strbuf_addch(&buf, '\n'); /* Make sure msg ends with newline */

	/* Convert notes tree to tree object */
	if (write_notes_tree(t, tree_sha1))
		die("Failed to write current notes tree to database");

	/* Create new commit for the tree object */
	if (!read_ref(t->ref, prev_commit)) { /* retrieve parent commit */
		parent = xmalloc(sizeof(*parent));
		parent->item = lookup_commit(prev_commit);
		parent->next = NULL;
	} else {
		hashclr(prev_commit);
		parent = NULL;
	}
	if (commit_tree(buf.buf + 7, tree_sha1, parent, new_commit, NULL))
		die("Failed to commit notes tree to database");

	/* Update notes ref with new commit */
	update_ref(buf.buf, t->ref, new_commit, prev_commit, 0, DIE_ON_ERR);

	strbuf_release(&buf);
	return 0;
}

combine_notes_fn parse_combine_notes_fn(const char *v)
