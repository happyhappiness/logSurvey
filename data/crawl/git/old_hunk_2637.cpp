	return out;
}

static void convert_to_utf8(struct mailinfo *mi,
			    struct strbuf *line, const char *charset)
{
	char *out;

	if (!mi->metainfo_charset || !charset || !*charset)
		return;

	if (same_encoding(mi->metainfo_charset, charset))
		return;
	out = reencode_string(line->buf, mi->metainfo_charset, charset);
	if (!out)
		die("cannot convert from %s to %s",
		    charset, mi->metainfo_charset);
	strbuf_attach(line, out, strlen(out), strlen(out));
}

static void decode_header(struct mailinfo *mi, struct strbuf *it)
