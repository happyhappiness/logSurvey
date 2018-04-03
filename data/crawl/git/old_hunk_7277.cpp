	/* Verify the tagger line */
	tagger_line = tag_line;

	if (memcmp(tagger_line, "tagger", 6) || (tagger_line[6] == '\n'))
		return error("char" PD_FMT ": could not find \"tagger\"", tagger_line - buffer);

	/* TODO: check for committer info + blank line? */
	/* Also, the minimum length is probably + "tagger .", or 63+8=71 */

	/* The actual stuff afterwards we don't care about.. */
	return 0;
