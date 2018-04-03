			tz = -tz;
	}

	switch (part) {
	case 'd':	/* date */
		strbuf_addstr(sb, show_date(date, tz, DATE_NORMAL));
		return;
	case 'D':	/* date, RFC2822 style */
		strbuf_addstr(sb, show_date(date, tz, DATE_RFC2822));
		return;
	case 'r':	/* date, relative */
		strbuf_addstr(sb, show_date(date, tz, DATE_RELATIVE));
		return;
	case 'i':	/* date, ISO 8601 */
		strbuf_addstr(sb, show_date(date, tz, DATE_ISO8601));
		return;
	}
}

static void format_commit_item(struct strbuf *sb, const char *placeholder,
                               void *context)
{
	const struct commit *commit = context;
	struct commit_list *p;
	int i;
	enum { HEADER, SUBJECT, BODY } state;
	const char *msg = commit->buffer;

	/* these are independent of the commit */
	switch (placeholder[0]) {
	case 'C':
		switch (placeholder[3]) {
		case 'd':	/* red */
			strbuf_addstr(sb, "\033[31m");
			return;
		case 'e':	/* green */
			strbuf_addstr(sb, "\033[32m");
			return;
		case 'u':	/* blue */
			strbuf_addstr(sb, "\033[34m");
			return;
		case 's':	/* reset color */
			strbuf_addstr(sb, "\033[m");
			return;
		}
	case 'n':		/* newline */
		strbuf_addch(sb, '\n');
		return;
	}

	/* these depend on the commit */
	if (!commit->object.parsed)
		parse_object(commit->object.sha1);

	switch (placeholder[0]) {
	case 'H':		/* commit hash */
		strbuf_addstr(sb, sha1_to_hex(commit->object.sha1));
		return;
	case 'h':		/* abbreviated commit hash */
		strbuf_addstr(sb, find_unique_abbrev(commit->object.sha1,
		                                     DEFAULT_ABBREV));
		return;
	case 'T':		/* tree hash */
		strbuf_addstr(sb, sha1_to_hex(commit->tree->object.sha1));
		return;
	case 't':		/* abbreviated tree hash */
		strbuf_addstr(sb, find_unique_abbrev(commit->tree->object.sha1,
		                                     DEFAULT_ABBREV));
		return;
	case 'P':		/* parent hashes */
		for (p = commit->parents; p; p = p->next) {
			if (p != commit->parents)
				strbuf_addch(sb, ' ');
			strbuf_addstr(sb, sha1_to_hex(p->item->object.sha1));
		}
		return;
	case 'p':		/* abbreviated parent hashes */
		for (p = commit->parents; p; p = p->next) {
			if (p != commit->parents)
				strbuf_addch(sb, ' ');
			strbuf_addstr(sb, find_unique_abbrev(
					p->item->object.sha1, DEFAULT_ABBREV));
		}
		return;
	case 'm':		/* left/right/bottom */
		strbuf_addch(sb, (commit->object.flags & BOUNDARY)
		                 ? '-'
		                 : (commit->object.flags & SYMMETRIC_LEFT)
		                 ? '<'
		                 : '>');
		return;
	}

	/* For the rest we have to parse the commit header. */
	for (i = 0, state = HEADER; msg[i] && state < BODY; i++) {
		int eol;
		for (eol = i; msg[eol] && msg[eol] != '\n'; eol++)
			; /* do nothing */

		if (state == SUBJECT) {
			if (placeholder[0] == 's') {
				strbuf_add(sb, msg + i, eol - i);
				return;
			}
			i = eol;
		}
		if (i == eol) {
			state++;
			/* strip empty lines */
			while (msg[eol + 1] == '\n')
				eol++;
		} else if (!prefixcmp(msg + i, "author ")) {
			if (placeholder[0] == 'a') {
				format_person_part(sb, placeholder[1],
				                   msg + i + 7, eol - i - 7);
				return;
			}
		} else if (!prefixcmp(msg + i, "committer ")) {
			if (placeholder[0] == 'c') {
				format_person_part(sb, placeholder[1],
				                   msg + i + 10, eol - i - 10);
				return;
			}
		} else if (!prefixcmp(msg + i, "encoding ")) {
			if (placeholder[0] == 'e') {
				strbuf_add(sb, msg + i + 9, eol - i - 9);
				return;
			}
		}
		i = eol;
	}
	if (msg[i] && placeholder[0] == 'b')	/* body */
		strbuf_addstr(sb, msg + i);
}

void format_commit_message(const struct commit *commit,
                           const void *format, struct strbuf *sb)
{
	const char *placeholders[] = {
		"H",		/* commit hash */
		"h",		/* abbreviated commit hash */
		"T",		/* tree hash */
		"t",		/* abbreviated tree hash */
		"P",		/* parent hashes */
		"p",		/* abbreviated parent hashes */
		"an",		/* author name */
		"ae",		/* author email */
		"ad",		/* author date */
		"aD",		/* author date, RFC2822 style */
		"ar",		/* author date, relative */
		"at",		/* author date, UNIX timestamp */
		"ai",		/* author date, ISO 8601 */
		"cn",		/* committer name */
		"ce",		/* committer email */
		"cd",		/* committer date */
		"cD",		/* committer date, RFC2822 style */
		"cr",		/* committer date, relative */
		"ct",		/* committer date, UNIX timestamp */
		"ci",		/* committer date, ISO 8601 */
		"e",		/* encoding */
		"s",		/* subject */
		"b",		/* body */
		"Cred",		/* red */
		"Cgreen",	/* green */
		"Cblue",	/* blue */
		"Creset",	/* reset color */
		"n",		/* newline */
		"m",		/* left/right/bottom */
		NULL
	};
	strbuf_expand(sb, format, placeholders, format_commit_item, (void *)commit);
}

static void pp_header(enum cmit_fmt fmt,
