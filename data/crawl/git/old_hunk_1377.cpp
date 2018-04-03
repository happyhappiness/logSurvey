
	for (p = opt->header_list; p; p = p->next) {
		if (p->token != GREP_PATTERN_HEAD)
			die("bug: a non-header pattern in grep header list.");
		if (p->field < GREP_HEADER_FIELD_MIN ||
		    GREP_HEADER_FIELD_MAX <= p->field)
			die("bug: unknown header field %d", p->field);
		compile_regexp(p, opt);
	}

