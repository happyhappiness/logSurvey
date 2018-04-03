	/* Verify the tagger line */
	tagger_line = tag_line;

	if (memcmp(tagger_line, "tagger ", 7) || (tagger_line[7] == '\n'))
		return error("char" PD_FMT ": could not find \"tagger \"",
			tagger_line - buffer);

	/*
	 * Check for correct form for name and email
	 * i.e. " <" followed by "> " on _this_ line
	 */
	tagger_line += 7;
	if (!(lb = strstr(tagger_line, " <")) || !(rb = strstr(lb+2, "> ")) ||
		strchr(tagger_line, '\n') < rb)
		return error("char" PD_FMT ": malformed tagger",
			tagger_line - buffer);

	/* Check for author name, at least one character, space is acceptable */
	if (lb == tagger_line)
		return error("char" PD_FMT ": missing tagger name",
			tagger_line - buffer);

	/* timestamp */
	tagger_line = rb + 2;
	if (*tagger_line == ' ')
		return error("char" PD_FMT ": malformed tag timestamp",
			tagger_line - buffer);
	for (;;) {
		unsigned char c = *tagger_line++;
		if (c == ' ')
			break;
		if (isdigit(c))
			continue;
		return error("char" PD_FMT ": malformed tag timestamp",
			tagger_line - buffer);
	}

	/* timezone, 5 digits [+-]hhmm, max. 1400 */
	if (!((tagger_line[0] == '+' || tagger_line[0] == '-') &&
	      isdigit(tagger_line[1]) && isdigit(tagger_line[2]) &&
	      isdigit(tagger_line[3]) && isdigit(tagger_line[4]) &&
	      tagger_line[5] == '\n' && atoi(tagger_line+1) <= 1400))
		return error("char" PD_FMT ": malformed tag timezone",
			tagger_line - buffer);
