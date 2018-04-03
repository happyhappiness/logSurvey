	am_destroy(state);
}

static int show_patch(struct am_state *state)
{
	struct strbuf sb = STRBUF_INIT;
	const char *patch_path;
	int len;

	patch_path = am_path(state, msgnum(state));
	len = strbuf_read_file(&sb, patch_path, 0);
	if (len < 0)
		die_errno(_("failed to read '%s'"), patch_path);

	setup_pager();
	write_in_full(1, sb.buf, sb.len);
	strbuf_release(&sb);
	return 0;
}

/**
 * parse_options() callback that validates and sets opt->value to the
 * PATCH_FORMAT_* enum value corresponding to `arg`.
