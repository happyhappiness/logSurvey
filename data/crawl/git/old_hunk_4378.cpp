	if (!(lb = strstr(tagger_line, " <")) || !(rb = strstr(lb+2, "> ")) ||
		strpbrk(tagger_line, "<>\n") != lb+1 ||
		strpbrk(lb+2, "><\n ") != rb)
		return error("char" PD_FMT ": malformed tagger field",
			tagger_line - buffer);

	/* Check for author name, at least one character, space is acceptable */
	if (lb == tagger_line)
		return error("char" PD_FMT ": missing tagger name",
			tagger_line - buffer);

	/* timestamp, 1 or more digits followed by space */
	tagger_line = rb + 2;
	if (!(len = strspn(tagger_line, "0123456789")))
		return error("char" PD_FMT ": missing tag timestamp",
			tagger_line - buffer);
	tagger_line += len;
	if (*tagger_line != ' ')
		return error("char" PD_FMT ": malformed tag timestamp",
			tagger_line - buffer);
	tagger_line++;

	/* timezone, 5 digits [+-]hhmm, max. 1400 */
	if (!((tagger_line[0] == '+' || tagger_line[0] == '-') &&
	      strspn(tagger_line+1, "0123456789") == 4 &&
	      tagger_line[5] == '\n' && atoi(tagger_line+1) <= 1400))
		return error("char" PD_FMT ": malformed tag timezone",
			tagger_line - buffer);
	tagger_line += 6;

	/* Verify the blank line separating the header from the body */
	if (*tagger_line != '\n')
		return error("char" PD_FMT ": trailing garbage in tag header",
			tagger_line - buffer);

	/* The actual stuff afterwards we don't care about.. */
	return 0;
}

#undef PD_FMT

int cmd_mktag(int argc, const char **argv, const char *prefix)
{
	struct strbuf buf = STRBUF_INIT;