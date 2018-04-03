	}
}

static int match_funcname(xdemitconf_t *xecfg, const char *bol, const char *eol)
{
	if (xecfg) {
		char buf[1];
		return xecfg->find_func(bol, eol - bol, buf, 1,
					xecfg->find_func_priv) >= 0;
	}

	if (bol == eol)
		return 0;
	if (isalpha(*bol) || *bol == '_' || *bol == '$')
		return 1;
	return 0;
}

static const char *find_funcname_matching_regexp(xdemitconf_t *xecfg, const char *start,
						 regex_t *regexp)
{
	int reg_error;
	regmatch_t match[1];
	while (1) {
		const char *bol, *eol;
		reg_error = regexec(regexp, start, 1, match, 0);
		if (reg_error == REG_NOMATCH)
			return NULL;
		else if (reg_error) {
			char errbuf[1024];
			regerror(reg_error, regexp, errbuf, 1024);
			die("-L parameter: regexec() failed: %s", errbuf);
		}
		/* determine extent of line matched */
		bol = start+match[0].rm_so;
		eol = start+match[0].rm_eo;
		while (bol > start && *bol != '\n')
			bol--;
		if (*bol == '\n')
			bol++;
		while (*eol && *eol != '\n')
			eol++;
		if (*eol == '\n')
			eol++;
		/* is it a funcname line? */
		if (match_funcname(xecfg, (char*) bol, (char*) eol))
			return bol;
		start = eol;
	}
}

static const char *parse_range_funcname(const char *arg, nth_line_fn_t nth_line_cb,
					void *cb_data, long lines, long *begin, long *end,
					const char *path)
{
	char *pattern;
	const char *term;
	struct userdiff_driver *drv;
	xdemitconf_t *xecfg = NULL;
	const char *start;
	const char *p;
	int reg_error;
	regex_t regexp;

	assert(*arg == ':');
	term = arg+1;
	while (*term && *term != ':') {
		if (*term == '\\' && *(term+1))
			term++;
		term++;
	}
	if (term == arg+1)
		return NULL;
	if (!begin) /* skip_range_arg case */
		return term;

	pattern = xstrndup(arg+1, term-(arg+1));

	start = nth_line_cb(cb_data, 0);

	drv = userdiff_find_by_path(path);
	if (drv && drv->funcname.pattern) {
		const struct userdiff_funcname *pe = &drv->funcname;
		xecfg = xcalloc(1, sizeof(*xecfg));
		xdiff_set_find_func(xecfg, pe->pattern, pe->cflags);
	}

	reg_error = regcomp(&regexp, pattern, REG_NEWLINE);
	if (reg_error) {
		char errbuf[1024];
		regerror(reg_error, &regexp, errbuf, 1024);
		die("-L parameter '%s': %s", pattern, errbuf);
	}

	p = find_funcname_matching_regexp(xecfg, (char*) start, &regexp);
	if (!p)
		die("-L parameter '%s': no match", pattern);
	*begin = 0;
	while (p > nth_line_cb(cb_data, *begin))
		(*begin)++;

	if (*begin >= lines)
		die("-L parameter '%s' matches at EOF", pattern);

	*end = *begin+1;
	while (*end < lines) {
		const char *bol = nth_line_cb(cb_data, *end);
		const char *eol = nth_line_cb(cb_data, *end+1);
		if (match_funcname(xecfg, bol, eol))
			break;
		(*end)++;
	}

	regfree(&regexp);
	free(xecfg);
	free(pattern);

	/* compensate for 1-based numbering */
	(*begin)++;

	return term;
}

int parse_range_arg(const char *arg, nth_line_fn_t nth_line_cb,
		    void *cb_data, long lines, long *begin, long *end,
		    const char *path)
{
	if (*arg == ':') {
		arg = parse_range_funcname(arg, nth_line_cb, cb_data, lines, begin, end, path);
		if (!arg || *arg)
			return -1;
		return 0;
	}

	arg = parse_loc(arg, nth_line_cb, cb_data, lines, 1, begin);

	if (*arg == ',')
