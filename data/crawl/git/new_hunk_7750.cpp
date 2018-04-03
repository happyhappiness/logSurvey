		die("could not open %s\n", git_path(commit_editmsg));

	stripspace(&sb, 0);

	if (signoff) {
		struct strbuf sob;
		int i;

		strbuf_init(&sob, 0);
		strbuf_addstr(&sob, sign_off_header);
		strbuf_addstr(&sob, fmt_ident(getenv("GIT_COMMITTER_NAME"),
					      getenv("GIT_COMMITTER_EMAIL"),
					      "", 1));
		strbuf_addch(&sob, '\n');

		for (i = sb.len - 1; i > 0 && sb.buf[i - 1] != '\n'; i--)
			; /* do nothing */
		if (prefixcmp(sb.buf + i, sob.buf))
			strbuf_addbuf(&sb, &sob);
		strbuf_release(&sob);
	}

	if (fwrite(sb.buf, 1, sb.len, fp) < sb.len)
		die("could not write commit template: %s\n",
		    strerror(errno));

	strbuf_release(&sb);

	if (in_merge && !no_edit)
