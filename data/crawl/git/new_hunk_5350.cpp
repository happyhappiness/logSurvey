		if (get_sha1(split[1]->buf, to_obj))
			die("Failed to resolve '%s' as a valid ref.", split[1]->buf);

		if (rewrite_cmd)
			err = copy_note_for_rewrite(c, from_obj, to_obj);
		else
			err = copy_note(t, from_obj, to_obj, force,
					combine_notes_overwrite);

		if (err) {
			error("Failed to copy notes from '%s' to '%s'",
