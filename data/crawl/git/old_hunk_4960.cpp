		goto out;
	}

	add_note(t, object, from_note, combine_notes_overwrite);
	commit_notes(t, "Notes added by 'git notes copy'");
out:
	free_notes(t);
