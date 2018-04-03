			tz = -tz;
	}

	interp_set_entry(table, 2, show_date(date, tz, DATE_NORMAL));
	interp_set_entry(table, 3, show_date(date, tz, DATE_RFC2822));
	interp_set_entry(table, 4, show_date(date, tz, DATE_RELATIVE));
	interp_set_entry(table, 6, show_date(date, tz, DATE_ISO8601));
}

void format_commit_message(const struct commit *commit,
                           const void *format, struct strbuf *sb)
{
	struct interp table[] = {
		{ "%H" },	/* commit hash */
		{ "%h" },	/* abbreviated commit hash */
		{ "%T" },	/* tree hash */
		{ "%t" },	/* abbreviated tree hash */
		{ "%P" },	/* parent hashes */
		{ "%p" },	/* abbreviated parent hashes */
		{ "%an" },	/* author name */
		{ "%ae" },	/* author email */
		{ "%ad" },	/* author date */
		{ "%aD" },	/* author date, RFC2822 style */
		{ "%ar" },	/* author date, relative */
		{ "%at" },	/* author date, UNIX timestamp */
		{ "%ai" },	/* author date, ISO 8601 */
		{ "%cn" },	/* committer name */
		{ "%ce" },	/* committer email */
		{ "%cd" },	/* committer date */
		{ "%cD" },	/* committer date, RFC2822 style */
		{ "%cr" },	/* committer date, relative */
		{ "%ct" },	/* committer date, UNIX timestamp */
		{ "%ci" },	/* committer date, ISO 8601 */
		{ "%e" },	/* encoding */
		{ "%s" },	/* subject */
		{ "%b" },	/* body */
		{ "%Cred" },	/* red */
		{ "%Cgreen" },	/* green */
		{ "%Cblue" },	/* blue */
		{ "%Creset" },	/* reset color */
		{ "%n" },	/* newline */
		{ "%m" },	/* left/right/bottom */
	};
	enum interp_index {
		IHASH = 0, IHASH_ABBREV,
		ITREE, ITREE_ABBREV,
		IPARENTS, IPARENTS_ABBREV,
		IAUTHOR_NAME, IAUTHOR_EMAIL,
		IAUTHOR_DATE, IAUTHOR_DATE_RFC2822, IAUTHOR_DATE_RELATIVE,
		IAUTHOR_TIMESTAMP, IAUTHOR_ISO8601,
		ICOMMITTER_NAME, ICOMMITTER_EMAIL,
		ICOMMITTER_DATE, ICOMMITTER_DATE_RFC2822,
		ICOMMITTER_DATE_RELATIVE, ICOMMITTER_TIMESTAMP,
		ICOMMITTER_ISO8601,
		IENCODING,
		ISUBJECT,
		IBODY,
		IRED, IGREEN, IBLUE, IRESET_COLOR,
		INEWLINE,
		ILEFT_RIGHT,
	};
	struct commit_list *p;
	char parents[1024];
	unsigned long len;
	int i;
	enum { HEADER, SUBJECT, BODY } state;
	const char *msg = commit->buffer;

	if (ILEFT_RIGHT + 1 != ARRAY_SIZE(table))
		die("invalid interp table!");

	/* these are independent of the commit */
	interp_set_entry(table, IRED, "\033[31m");
	interp_set_entry(table, IGREEN, "\033[32m");
	interp_set_entry(table, IBLUE, "\033[34m");
	interp_set_entry(table, IRESET_COLOR, "\033[m");
	interp_set_entry(table, INEWLINE, "\n");

	/* these depend on the commit */
	if (!commit->object.parsed)
		parse_object(commit->object.sha1);
	interp_set_entry(table, IHASH, sha1_to_hex(commit->object.sha1));
	interp_set_entry(table, IHASH_ABBREV,
			find_unique_abbrev(commit->object.sha1,
				DEFAULT_ABBREV));
	interp_set_entry(table, ITREE, sha1_to_hex(commit->tree->object.sha1));
	interp_set_entry(table, ITREE_ABBREV,
			find_unique_abbrev(commit->tree->object.sha1,
				DEFAULT_ABBREV));
	interp_set_entry(table, ILEFT_RIGHT,
			 (commit->object.flags & BOUNDARY)
			 ? "-"
			 : (commit->object.flags & SYMMETRIC_LEFT)
			 ? "<"
			 : ">");

	parents[1] = 0;
	for (i = 0, p = commit->parents;
			p && i < sizeof(parents) - 1;
			p = p->next)
		i += snprintf(parents + i, sizeof(parents) - i - 1, " %s",
			sha1_to_hex(p->item->object.sha1));
	interp_set_entry(table, IPARENTS, parents + 1);

	parents[1] = 0;
	for (i = 0, p = commit->parents;
			p && i < sizeof(parents) - 1;
			p = p->next)
		i += snprintf(parents + i, sizeof(parents) - i - 1, " %s",
			find_unique_abbrev(p->item->object.sha1,
				DEFAULT_ABBREV));
	interp_set_entry(table, IPARENTS_ABBREV, parents + 1);

	for (i = 0, state = HEADER; msg[i] && state < BODY; i++) {
		int eol;
		for (eol = i; msg[eol] && msg[eol] != '\n'; eol++)
			; /* do nothing */

		if (state == SUBJECT) {
			table[ISUBJECT].value = xmemdupz(msg + i, eol - i);
			i = eol;
		}
		if (i == eol) {
			state++;
			/* strip empty lines */
			while (msg[eol + 1] == '\n')
				eol++;
		} else if (!prefixcmp(msg + i, "author "))
			fill_person(table + IAUTHOR_NAME,
					msg + i + 7, eol - i - 7);
		else if (!prefixcmp(msg + i, "committer "))
			fill_person(table + ICOMMITTER_NAME,
					msg + i + 10, eol - i - 10);
		else if (!prefixcmp(msg + i, "encoding "))
			table[IENCODING].value =
				xmemdupz(msg + i + 9, eol - i - 9);
		i = eol;
	}
	if (msg[i])
		table[IBODY].value = xstrdup(msg + i);

	len = interpolate(sb->buf + sb->len, strbuf_avail(sb),
				format, table, ARRAY_SIZE(table));
	if (len > strbuf_avail(sb)) {
		strbuf_grow(sb, len);
		interpolate(sb->buf + sb->len, strbuf_avail(sb) + 1,
					format, table, ARRAY_SIZE(table));
	}
	strbuf_setlen(sb, sb->len + len);
	interp_clear_table(table, ARRAY_SIZE(table));
}

static void pp_header(enum cmit_fmt fmt,
