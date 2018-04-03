			break;
		if (c > ' ')
			continue;
		return error("char%"PRIuMAX": could not verify tag name",
				(uintmax_t) (tag_line - buffer));
	}

	/* Verify the tagger line */
	tagger_line = tag_line;

	if (memcmp(tagger_line, "tagger ", 7))
		return error("char%"PRIuMAX": could not find \"tagger \"",
			(uintmax_t) (tagger_line - buffer));

	/*
	 * Check for correct form for name and email
