					combine_notes_overwrite);

		if (err) {
			error("Failed to copy notes from '%s' to '%s'",
			      split[0]->buf, split[1]->buf);
			ret = 1;
		}
