
	prepare_note_data(&object, &d, note ? note->hash : NULL);
	if (d.buf.len || allow_empty) {
		write_note_data(&d, &new_note);
		if (add_note(t, &object, &new_note, combine_notes_overwrite))
			die("BUG: combine_notes_overwrite failed");
		commit_notes(t, "Notes added by 'git notes add'");
