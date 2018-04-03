		die(_("unable to write index file"));
}

/**
 * Returns 1 if the index differs from HEAD, 0 otherwise. When on an unborn
 * branch, returns 1 if there are entries in the index, 0 otherwise. If an
 * strbuf is provided, the space-separated list of files that differ will be
 * appended to it.
 */
static int index_has_changes(struct strbuf *sb)
{
	unsigned char head[GIT_SHA1_RAWSZ];
	int i;

	if (!get_sha1_tree("HEAD", head)) {
		struct diff_options opt;

		diff_setup(&opt);
		DIFF_OPT_SET(&opt, EXIT_WITH_STATUS);
		if (!sb)
			DIFF_OPT_SET(&opt, QUICK);
		do_diff_cache(head, &opt);
		diffcore_std(&opt);
		for (i = 0; sb && i < diff_queued_diff.nr; i++) {
			if (i)
				strbuf_addch(sb, ' ');
			strbuf_addstr(sb, diff_queued_diff.queue[i]->two->path);
		}
		diff_flush(&opt);
		return DIFF_OPT_TST(&opt, HAS_CHANGES) != 0;
	} else {
		for (i = 0; sb && i < active_nr; i++) {
			if (i)
				strbuf_addch(sb, ' ');
			strbuf_addstr(sb, active_cache[i]->name);
		}
		return !!active_nr;
	}
}

/**
 * Parses `mail` using git-mailinfo, extracting its patch and authorship info.
 * state->msg will be set to the patch message. state->author_name,
