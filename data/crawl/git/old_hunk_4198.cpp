	}
}

int grep_buffer(struct grep_opt *opt, const char *name, char *buf, unsigned long size)
{
	/*
	 * we do not have to do the two-pass grep when we do not check
	 * buffer-wide "all-match".
	 */
	if (!opt->all_match)
		return grep_buffer_1(opt, name, buf, size, 0);

	/* Otherwise the toplevel "or" terms hit a bit differently.
	 * We first clear hit markers from them.
	 */
	clr_hit_marker(opt->pattern_expression);
	grep_buffer_1(opt, name, buf, size, 1);

	if (!chk_hit_marker(opt->pattern_expression))
		return 0;

	return grep_buffer_1(opt, name, buf, size, 0);
}
