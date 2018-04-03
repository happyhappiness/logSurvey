	return compile_pattern_or(list);
}

void compile_grep_patterns(struct grep_opt *opt)
{
	struct grep_pat *p;
	struct grep_expr *header_expr = NULL;

	if (opt->header_list) {
		p = opt->header_list;
		header_expr = compile_pattern_expr(&p);
		if (p)
			die("incomplete pattern expression: %s", p->pattern);
		for (p = opt->header_list; p; p = p->next) {
			switch (p->token) {
			case GREP_PATTERN: /* atom */
			case GREP_PATTERN_HEAD:
			case GREP_PATTERN_BODY:
				compile_regexp(p, opt);
				break;
			default:
				opt->extended = 1;
				break;
			}
		}
	}

	for (p = opt->pattern_list; p; p = p->next) {
		switch (p->token) {
