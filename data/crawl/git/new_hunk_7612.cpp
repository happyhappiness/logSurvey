	sline->p_lno[i] = sline->p_lno[j];
}

static void dump_quoted_path(const char *head,
			     const char *prefix,
			     const char *path,
			     const char *c_meta, const char *c_reset)
{
	static struct strbuf buf = STRBUF_INIT;

	strbuf_reset(&buf);
	strbuf_addstr(&buf, c_meta);
	strbuf_addstr(&buf, head);
	if (quote_c_style(prefix, NULL, NULL, 0) ||
	    quote_c_style(path, NULL, NULL, 0)) {
		strbuf_addch(&buf, '"');
		quote_c_style(prefix, &buf, NULL, 1);
		quote_c_style(path, &buf, NULL, 1);
		strbuf_addch(&buf, '"');
	} else {
		strbuf_addstr(&buf, prefix);
		strbuf_addstr(&buf, path);
	}
	strbuf_addstr(&buf, c_reset);
	puts(buf.buf);
}

static void show_patch_diff(struct combine_diff_path *elem, int num_parent,
