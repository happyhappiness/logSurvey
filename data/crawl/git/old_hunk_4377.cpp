			break;
		if (c > ' ')
			continue;
		return error("char" PD_FMT ": could not verify tag name", tag_line - buffer);
	}

	/* Verify the tagger line */
	tagger_line = tag_line;

	if (memcmp(tagger_line, "tagger ", 7))
		return error("char" PD_FMT ": could not find \"tagger \"",
			tagger_line - buffer);

	/*
	 * Check for correct form for name and email
