	}

	if (d.buf.len || allow_empty) {
		write_note_data(&d, new_note.hash);
		if (add_note(t, &object, &new_note, combine_notes_overwrite))
			die("BUG: combine_notes_overwrite failed");
		logmsg = xstrfmt("Notes added by 'git notes %s'", argv[0]);
