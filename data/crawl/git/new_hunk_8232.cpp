		size = FIRST_FEW_BYTES;
	return !!memchr(ptr, 0, size);
}

struct ff_regs {
	int nr;
	struct ff_reg {
		regex_t re;
		int negate;
	} *array;
};

static long ff_regexp(const char *line, long len,
		char *buffer, long buffer_size, void *priv)
{
	char *line_buffer = xstrndup(line, len); /* make NUL terminated */
	struct ff_regs *regs = priv;
	regmatch_t pmatch[2];
	int result = 0, i;

	for (i = 0; i < regs->nr; i++) {
		struct ff_reg *reg = regs->array + i;
		if (reg->negate ^ !!regexec(&reg->re,
					line_buffer, 2, pmatch, 0)) {
			free(line_buffer);
			return -1;
		}
	}
	i = pmatch[1].rm_so >= 0 ? 1 : 0;
	line += pmatch[i].rm_so;
	result = pmatch[i].rm_eo - pmatch[i].rm_so;
	if (result > buffer_size)
		result = buffer_size;
	else
		while (result > 0 && (isspace(line[result - 1]) ||
					line[result - 1] == '\n'))
			result--;
	memcpy(buffer, line, result);
	free(line_buffer);
	return result;
}

void xdiff_set_find_func(xdemitconf_t *xecfg, const char *value)
{
	int i;
	struct ff_regs *regs;

	xecfg->find_func = ff_regexp;
	regs = xecfg->find_func_priv = xmalloc(sizeof(struct ff_regs));
	for (i = 0, regs->nr = 1; value[i]; i++)
		if (value[i] == '\n')
			regs->nr++;
	regs->array = xmalloc(regs->nr * sizeof(struct ff_reg));
	for (i = 0; i < regs->nr; i++) {
		struct ff_reg *reg = regs->array + i;
		const char *ep = strchr(value, '\n'), *expression;
		char *buffer = NULL;

		reg->negate = (*value == '!');
		if (reg->negate && i == regs->nr - 1)
			die("Last expression must not be negated: %s", value);
		if (*value == '!')
			value++;
		if (ep)
			expression = buffer = xstrndup(value, ep - value);
		else
			expression = value;
		if (regcomp(&reg->re, expression, 0))
			die("Invalid regexp to look for hunk header: %s", expression);
		if (buffer)
			free(buffer);
		value = ep + 1;
	}
}
