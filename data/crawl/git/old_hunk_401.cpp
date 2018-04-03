	if (!p->pcre1_regexp)
		compile_regexp_failed(p, error);

	p->pcre1_extra_info = pcre_study(p->pcre1_regexp, 0, &error);
	if (!p->pcre1_extra_info && error)
		die("%s", error);
}

static int pcre1match(struct grep_pat *p, const char *line, const char *eol,
