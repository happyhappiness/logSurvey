	}
	argc = j;

	if (do_signoff) {
		const char *committer;
		const char *endpos;
		committer = git_committer_info(IDENT_ERROR_ON_NO_NAME);
		endpos = strchr(committer, '>');
		if (!endpos)
			die("bogus committer info %s", committer);
		add_signoff = xmemdupz(committer, endpos - committer + 1);
	}

	for (i = 0; i < extra_hdr_nr; i++) {
		strbuf_addstr(&buf, extra_hdr[i]);
		strbuf_addch(&buf, '\n');