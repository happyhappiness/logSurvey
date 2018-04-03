		}
	}

	pp_header(fmt, abbrev, dmode, encoding,
		  commit, &msg, &len,
		  &offset, buf_p, space_p);
	if (fmt != CMIT_FMT_ONELINE && !subject) {
		ALLOC_GROW(*buf_p, offset + 20, *space_p);
		(*buf_p)[offset++] = '\n';
	}

	/* Skip excess blank lines at the beginning of body, if any... */
	for (;;) {
		int linelen = get_one_line(msg, len);
		int ll = linelen;
		if (!linelen)
			break;
		if (!is_empty_line(msg, &ll))
			break;
		msg += linelen;
		len -= linelen;
	}

	/* These formats treat the title line specially. */
	if (fmt == CMIT_FMT_ONELINE
	    || fmt == CMIT_FMT_EMAIL)
		pp_title_line(fmt, &msg, &len, &offset,
			      buf_p, space_p, indent,
			      subject, after_subject, encoding,
			      plain_non_ascii);

	beginning_of_body = offset;
	if (fmt != CMIT_FMT_ONELINE)
		pp_remainder(fmt, &msg, &len, &offset,
			     buf_p, space_p, indent);

	while (offset && isspace((*buf_p)[offset-1]))
		offset--;

	ALLOC_GROW(*buf_p, offset + 20, *space_p);
	buf = *buf_p;

	/* Make sure there is an EOLN for the non-oneline case */
	if (fmt != CMIT_FMT_ONELINE)
		buf[offset++] = '\n';

	/*
	 * The caller may append additional body text in e-mail
	 * format.  Make sure we did not strip the blank line
	 * between the header and the body.
	 */
	if (fmt == CMIT_FMT_EMAIL && offset <= beginning_of_body)
		buf[offset++] = '\n';
	buf[offset] = '\0';
	free(reencoded);
	return offset;
}