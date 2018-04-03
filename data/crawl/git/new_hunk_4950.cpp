	expand_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	t = init_notes_check("merge");

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
		    remote_ref.buf, default_notes_ref());
	o.commit_msg = msg.buf + 7; // skip "notes: " prefix

	result = notes_merge(&o, t, result_sha1);

	if (result >= 0) /* Merge resulted (trivially) in result_sha1 */
		/* Update default notes ref with new commit */
		update_ref(msg.buf, default_notes_ref(), result_sha1, NULL,
			   0, DIE_ON_ERR);
	else
		/* TODO: */
		die("'git notes merge' cannot yet handle conflicts!");

	free_notes(t);
	strbuf_release(&remote_ref);
	strbuf_release(&msg);
	return 0;
