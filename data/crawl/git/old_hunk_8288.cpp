		}
	}

	space = *space_p;
	buf = *buf_p;

	/*
	 * We do not want to repeatedly realloc below, so
	 * preallocate with enough slop to hold MIME headers,
	 * "Subject: " prefix, etc.
	 */
	slop = 1000;
	if (subject)
		slop += strlen(subject);
	if (after_subject)
		slop += strlen(after_subject);
	if (space < strlen(msg) + slop) {
		space = strlen(msg) + slop;
		buf = xrealloc(buf, space);
		*space_p = space;
		*buf_p = buf;
	}

	for (;;) {
		const char *line = msg;
		int linelen = get_one_line(msg, len);

		if (!linelen)
			break;

		/* 20 would cover indent and leave us some slop */
		if (offset + linelen + 20 > space) {
			space = offset + linelen + 20;
			buf = xrealloc(buf, space);
			*buf_p = buf;
			*space_p = space;
		}

		msg += linelen;
		len -= linelen;
		if (hdr) {
			if (linelen == 1) {
				hdr = 0;
				if ((fmt != CMIT_FMT_ONELINE) && !subject)
					buf[offset++] = '\n';
				continue;
			}
			if (fmt == CMIT_FMT_RAW) {
				memcpy(buf + offset, line, linelen);
				offset += linelen;
				continue;
			}
			if (!memcmp(line, "parent ", 7)) {
				if (linelen != 48)
					die("bad parent line in commit");
				continue;
			}

			if (!parents_shown) {
				offset += add_merge_info(fmt, buf + offset,
							 commit, abbrev);
				parents_shown = 1;
				continue;
			}
			/*
			 * MEDIUM == DEFAULT shows only author with dates.
			 * FULL shows both authors but not dates.
			 * FULLER shows both authors and dates.
			 */
			if (!memcmp(line, "author ", 7))
				offset += add_user_info("Author", fmt,
							buf + offset,
							line + 7,
							dmode,
							encoding);
			if (!memcmp(line, "committer ", 10) &&
			    (fmt == CMIT_FMT_FULL || fmt == CMIT_FMT_FULLER))
				offset += add_user_info("Commit", fmt,
							buf + offset,
							line + 10,
							dmode,
							encoding);
			continue;
		}

		if (!subject)
			body = 1;

		if (is_empty_line(line, &linelen)) {
			if (!seen_title)
				continue;
			if (!body)
				continue;
			if (subject)
				continue;
			if (fmt == CMIT_FMT_SHORT)
				break;
		}

		seen_title = 1;
		if (subject) {
			int slen = strlen(subject);
			memcpy(buf + offset, subject, slen);
			offset += slen;
			offset += add_rfc2047(buf + offset, line, linelen,
					      encoding);
		}
		else {
			memset(buf + offset, ' ', indent);
			memcpy(buf + offset + indent, line, linelen);
			offset += linelen + indent;
		}
		buf[offset++] = '\n';
		if (fmt == CMIT_FMT_ONELINE)
			break;
		if (subject && plain_non_ascii) {
			int sz;
			char header[512];
			const char *header_fmt =
				"MIME-Version: 1.0\n"
				"Content-Type: text/plain; charset=%s\n"
				"Content-Transfer-Encoding: 8bit\n";
			sz = snprintf(header, sizeof(header), header_fmt,
				      encoding);
			if (sizeof(header) < sz)
				die("Encoding name %s too long", encoding);
			memcpy(buf + offset, header, sz);
			offset += sz;
		}
		if (after_subject) {
			int slen = strlen(after_subject);
			if (slen > space - offset - 1)
				slen = space - offset - 1;
			memcpy(buf + offset, after_subject, slen);
			offset += slen;
			after_subject = NULL;
		}
		subject = NULL;
	}
	while (offset && isspace(buf[offset-1]))
		offset--;
	/* Make sure there is an EOLN for the non-oneline case */
	if (fmt != CMIT_FMT_ONELINE)
		buf[offset++] = '\n';
	/*
	 * make sure there is another EOLN to separate the headers from whatever
	 * body the caller appends if we haven't already written a body
	 */
	if (fmt == CMIT_FMT_EMAIL && !body)
		buf[offset++] = '\n';
	buf[offset] = '\0';

	free(reencoded);
	return offset;
}