		die("could not open %s\n", git_path(commit_editmsg));

	stripspace(&sb, 0);
	if (fwrite(sb.buf, 1, sb.len, fp) < sb.len)
		die("could not write commit template: %s\n",
		    strerror(errno));

	if (signoff) {
		const char *info, *bol;

		info = git_committer_info(1);
		strbuf_addch(&sb, '\0');
		bol = strrchr(sb.buf + sb.len - 1, '\n');
		if (!bol || prefixcmp(bol, sign_off_header))
			fprintf(fp, "\n");
		fprintf(fp, "%s%s\n", sign_off_header, git_committer_info(1));
	}

	strbuf_release(&sb);

	if (in_merge && !no_edit)
