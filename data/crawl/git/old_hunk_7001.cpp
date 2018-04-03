
	if (!strcmp(metainfo_charset, charset))
		return;
	out = reencode_string(line, metainfo_charset, charset);
	if (!out)
		die("cannot convert from %s to %s\n",
		    charset, metainfo_charset);
	strlcpy(line, out, linesize);
	free(out);
}

static int decode_header_bq(char *it, unsigned itsize)
{
	char *in, *out, *ep, *cp, *sp;
	char outbuf[1000];
	int rfc2047 = 0;

	in = it;
	out = outbuf;
	while ((ep = strstr(in, "=?")) != NULL) {
		int sz, encoding;
		char charset_q[256], piecebuf[256];
		rfc2047 = 1;

		if (in != ep) {
			sz = ep - in;
			memcpy(out, in, sz);
			out += sz;
			in += sz;
		}
		/* E.g.
		 * ep : "=?iso-2022-jp?B?GyR...?= foo"
		 * ep : "=?ISO-8859-1?Q?Foo=FCbar?= baz"
		 */
		ep += 2;
		cp = strchr(ep, '?');
		if (!cp)
			return rfc2047; /* no munging */
		for (sp = ep; sp < cp; sp++)
			charset_q[sp - ep] = tolower(*sp);
		charset_q[cp - ep] = 0;
		encoding = cp[1];
		if (!encoding || cp[2] != '?')
			return rfc2047; /* no munging */
		ep = strstr(cp + 3, "?=");
		if (!ep)
			return rfc2047; /* no munging */
		switch (tolower(encoding)) {
		default:
			return rfc2047; /* no munging */
		case 'b':
			sz = decode_b_segment(cp + 3, piecebuf, sizeof(piecebuf), ep);
			break;
		case 'q':
			sz = decode_q_segment(cp + 3, piecebuf, sizeof(piecebuf), ep, 1);
			break;
		}
		if (sz < 0)
			return rfc2047;
		if (metainfo_charset)
			convert_to_utf8(piecebuf, sizeof(piecebuf), charset_q);

		sz = strlen(piecebuf);
		if (outbuf + sizeof(outbuf) <= out + sz)
			return rfc2047; /* no munging */
		strcpy(out, piecebuf);
		out += sz;
		in = ep + 2;
	}
	strcpy(out, in);
	strlcpy(it, outbuf, itsize);
	return rfc2047;
}

static void decode_header(char *it, unsigned itsize)
{

	if (decode_header_bq(it, itsize))
		return;
	/* otherwise "it" is a straight copy of the input.
	 * This can be binary guck but there is no charset specified.
	 */
	if (metainfo_charset)
		convert_to_utf8(it, itsize, "");
}

static int decode_transfer_encoding(char *line, unsigned linesize, int inputlen)
{
	char *ep;

	switch (transfer_encoding) {
	case TE_QP:
		ep = line + inputlen;
		return decode_q_segment(line, line, linesize, ep, 0);
	case TE_BASE64:
		ep = line + inputlen;
		return decode_b_segment(line, line, linesize, ep);
	case TE_DONTCARE:
	default:
		return inputlen;
	}
}

static int handle_filter(char *line, unsigned linesize, int linelen);

static int find_boundary(void)
{
	while(fgets(line, sizeof(line), fin) != NULL) {
		if (is_multipart_boundary(line))
			return 1;
	}
	return 0;
}

static int handle_boundary(void)
{
	char newline[]="\n";
again:
	if (!memcmp(line+content_top->boundary_len, "--", 2)) {
		/* we hit an end boundary */
		/* pop the current boundary off the stack */
		free(content_top->boundary);

		/* technically won't happen as is_multipart_boundary()
		   will fail first.  But just in case..
