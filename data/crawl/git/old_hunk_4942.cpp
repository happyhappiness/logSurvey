		/* Update default notes ref with new commit */
		update_ref(msg.buf, default_notes_ref(), result_sha1, NULL,
			   0, DIE_ON_ERR);
	else /* Merge has unresolved conflicts */
		printf("Automatic notes merge failed. Fix conflicts in %s.\n",
		       git_path(NOTES_MERGE_WORKTREE));

	free_notes(t);
	strbuf_release(&remote_ref);
