
	if (!strcmp(metainfo_charset, charset))
		return;
	out = reencode_string(line->buf, metainfo_charset, charset);
	if (!out)
		die("cannot convert from %s to %s\n",
		    charset, metainfo_charset);
	strbuf_attach(line, out, strlen(out), strlen(out));
}

static int decode_header_bq(struct strbuf *it)
{
	char *in, *ep, *cp;
	struct strbuf outbuf = STRBUF_INIT, *dec;
	struct strbuf charset_q = STRBUF_INIT, piecebuf = STRBUF_INIT;
	int rfc2047 = 0;

	in = it->buf;
	while (in - it->buf <= it->len && (ep = strstr(in, "=?")) != NULL) {
		int encoding;
		strbuf_reset(&charset_q);
		strbuf_reset(&piecebuf);
		rfc2047 = 1;

		if (in != ep) {
			strbuf_add(&outbuf, in, ep - in);
			in = ep;
		}
		/* E.g.
		 * ep : "=?iso-2022-jp?B?GyR...?= foo"
		 * ep : "=?ISO-8859-1?Q?Foo=FCbar?= baz"
		 */
		ep += 2;

		if (ep - it->buf >= it->len || !(cp = strchr(ep, '?')))
			goto decode_header_bq_out;

		if (cp + 3 - it->buf > it->len)
			goto decode_header_bq_out;
		strbuf_add(&charset_q, ep, cp - ep);
		strbuf_tolower(&charset_q);

		encoding = cp[1];
		if (!encoding || cp[2] != '?')
			goto decode_header_bq_out;
		ep = strstr(cp + 3, "?=");
		if (!ep)
			goto decode_header_bq_out;
		strbuf_add(&piecebuf, cp + 3, ep - cp - 3);
		switch (tolower(encoding)) {
		default:
			goto decode_header_bq_out;
		case 'b':
			dec = decode_b_segment(&piecebuf);
			break;
		case 'q':
			dec = decode_q_segment(&piecebuf, 1);
			break;
		}
		if (metainfo_charset)
			convert_to_utf8(dec, charset_q.buf);

		strbuf_addbuf(&outbuf, dec);
		strbuf_release(dec);
		free(dec);
		in = ep + 2;
	}
	strbuf_addstr(&outbuf, in);
	strbuf_reset(it);
	strbuf_addbuf(it, &outbuf);
decode_header_bq_out:
	strbuf_release(&outbuf);
	strbuf_release(&charset_q);
	strbuf_release(&piecebuf);
	return rfc2047;
}

static void decode_header(struct strbuf *it)
{
	if (decode_header_bq(it))
		return;
	/* otherwise "it" is a straight copy of the input.
	 * This can be binary guck but there is no charset specified.
	 */
	if (metainfo_charset)
		convert_to_utf8(it, "");
}

static void decode_transfer_encoding(struct strbuf *line)
{
	struct strbuf *ret;

	switch (transfer_encoding) {
	case TE_QP:
		ret = decode_q_segment(line, 0);
		break;
	case TE_BASE64:
		ret = decode_b_segment(line);
		break;
	case TE_DONTCARE:
	default:
		return;
	}
	strbuf_reset(line);
	strbuf_addbuf(line, ret);
	strbuf_release(ret);
	free(ret);
}

static void handle_filter(struct strbuf *line);

static int find_boundary(void)
{
	while (!strbuf_getline(&line, fin, '\n')) {
		if (is_multipart_boundary(&line))
			return 1;
	}
	return 0;
}

static int handle_boundary(void)
{
	struct strbuf newline = STRBUF_INIT;

	strbuf_addch(&newline, '\n');
again:
	if (line.len >= (*content_top)->len + 2 &&
	    !memcmp(line.buf + (*content_top)->len, "--", 2)) {
		/* we hit an end boundary */
		/* pop the current boundary off the stack */
		strbuf_release(*content_top);
		free(*content_top);
		*content_top = NULL;

		/* technically won't happen as is_multipart_boundary()
		   will fail first.  But just in case..
