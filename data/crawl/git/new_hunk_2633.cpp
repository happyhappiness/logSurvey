	if (same_encoding(mi->metainfo_charset, charset))
		return 0;
	out = reencode_string(line->buf, mi->metainfo_charset, charset);
	if (!out) {
		mi->input_error = -1;
		return error("cannot convert from %s to %s",
			     charset, mi->metainfo_charset);
	}
	strbuf_attach(line, out, strlen(out), strlen(out));
	return 0;
}
