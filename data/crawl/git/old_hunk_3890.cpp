			     PARSE_OPT_KEEP_ARGV0 | PARSE_OPT_KEEP_UNKNOWN |
			     PARSE_OPT_KEEP_DASHDASH);

	if (do_signoff) {
		const char *committer;
		const char *endpos;
		committer = git_committer_info(IDENT_STRICT);
		endpos = strchr(committer, '>');
		if (!endpos)
			die(_("bogus committer info %s"), committer);
		add_signoff = xmemdupz(committer, endpos - committer + 1);
	}

	for (i = 0; i < extra_hdr.nr; i++) {
		strbuf_addstr(&buf, extra_hdr.items[i].string);
		strbuf_addch(&buf, '\n');
