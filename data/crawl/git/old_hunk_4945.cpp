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
}

static int remove_cmd(int argc, const char **argv, const char *prefix)
