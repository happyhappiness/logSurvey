	return parse_reuse_arg(opt, arg, unset);
}

void commit_notes(struct notes_tree *t, const char *msg)
{
	struct strbuf buf = STRBUF_INIT;
	unsigned char commit_sha1[20];

	if (!t)
		t = &default_notes_tree;
	if (!t->initialized || !t->ref || !*t->ref)
		die("Cannot commit uninitialized/unreferenced notes tree");
	if (!t->dirty)
		return; /* don't have to commit an unchanged tree */

	/* Prepare commit message and reflog message */
	strbuf_addstr(&buf, "notes: "); /* commit message starts at index 7 */
	strbuf_addstr(&buf, msg);
	if (buf.buf[buf.len - 1] != '\n')
		strbuf_addch(&buf, '\n'); /* Make sure msg ends with newline */

	create_notes_commit(t, NULL, buf.buf + 7, commit_sha1);
	update_ref(buf.buf, t->ref, commit_sha1, NULL, 0, DIE_ON_ERR);

	strbuf_release(&buf);
}

combine_notes_fn parse_combine_notes_fn(const char *v)
