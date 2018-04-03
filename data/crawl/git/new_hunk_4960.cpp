		goto out;
	}

	if (add_note(t, object, from_note, combine_notes_overwrite))
		die("BUG: combine_notes_overwrite failed");
	commit_notes(t, "Notes added by 'git notes copy'");
out:
	free_notes(t);
