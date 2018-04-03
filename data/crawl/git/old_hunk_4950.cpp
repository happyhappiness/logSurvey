	expand_notes_ref(&remote_ref);
	o.remote_ref = remote_ref.buf;

	result = notes_merge(&o, result_sha1);

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
		    remote_ref.buf, default_notes_ref());
	if (result == 0) { /* Merge resulted (trivially) in result_sha1 */
		/* Update default notes ref with new commit */
		update_ref(msg.buf, default_notes_ref(), result_sha1, NULL,
			   0, DIE_ON_ERR);
	} else {
		/* TODO: */
		die("'git notes merge' cannot yet handle non-trivial merges!");
	}

	strbuf_release(&remote_ref);
	strbuf_release(&msg);
	return 0;
