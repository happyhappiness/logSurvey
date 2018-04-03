	if (eflags & REG_NOTBOL)
		flags |= PCRE_NOTBOL;

	ret = pcre_exec(p->pcre1_regexp, p->pcre1_extra_info, line, eol - line,
			0, flags, ovector, ARRAY_SIZE(ovector));
	if (ret < 0 && ret != PCRE_ERROR_NOMATCH)
		die("pcre_exec failed with error code %d", ret);
	if (ret > 0) {
