	char *msg = commit->buffer;
	char *out;

	if (!output_encoding || !*output_encoding)
		return msg;
	encoding = get_header(commit, msg, "encoding");
	use_encoding = encoding ? encoding : utf8;
	if (same_encoding(use_encoding, output_encoding))
		if (encoding) /* we'll strip encoding header later */
			out = xstrdup(commit->buffer);
		else
			return msg; /* nothing to do */
	else
		out = reencode_string(commit->buffer,
				      output_encoding, use_encoding);
	if (out)
		out = replace_encoding_header(out, output_encoding);

