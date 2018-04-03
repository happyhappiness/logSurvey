	*extra_headers_p = extra_headers;
}

static void show_signature(struct rev_info *opt, struct commit *commit)
{
	struct strbuf payload = STRBUF_INIT;
	struct strbuf signature = STRBUF_INIT;
	struct strbuf gpg_output = STRBUF_INIT;
	int status;
	const char *color, *reset, *bol, *eol;

	if (parse_signed_commit(commit->object.sha1, &payload, &signature) <= 0)
		goto out;
