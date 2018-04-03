
	if (is_null_sha1(new_note))
		remove_note(t, object);
	else
		add_note(t, object, new_note, combine_notes_overwrite);

	snprintf(logmsg, sizeof(logmsg), "Notes %s by 'git notes %s'",
		 is_null_sha1(new_note) ? "removed" : "added", "add");
