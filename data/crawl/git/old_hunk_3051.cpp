	strbuf_addf(&sb, "%s/commondir", sb_repo.buf);
	write_file(sb.buf, 1, "../..\n");

	fprintf_ln(stderr, _("Enter %s (identifier %s)"), path, name);

	setenv("GIT_CHECKOUT_NEW_WORKTREE", "1", 1);
	setenv(GIT_DIR_ENVIRONMENT, sb_git.buf, 1);