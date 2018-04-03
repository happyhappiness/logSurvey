                     const struct option *opt, int flags)
{
	const char *s, *arg;
	const int unset = flags & OPT_UNSET;

	if (unset && p->opt)
		return opterror(opt, "takes no value", flags);
	if (unset && (opt->flags & PARSE_OPT_NONEG))
		return opterror(opt, "isn't available", flags);

	if (!(flags & OPT_SHORT) && p->opt) {
		switch (opt->type) {
		case OPTION_CALLBACK:
			if (!(opt->flags & PARSE_OPT_NOARG))
				break;
			/* FALLTHROUGH */
		case OPTION_BOOLEAN:
		case OPTION_BIT:
		case OPTION_SET_INT:
		case OPTION_SET_PTR:
			return opterror(opt, "takes no value", flags);
		default:
			break;
		}
	}

	arg = p->opt ? p->opt : (p->argc > 1 ? p->argv[1] : NULL);
	switch (opt->type) {
	case OPTION_BIT:
		if (unset)
			*(int *)opt->value &= ~opt->defval;
		else
			*(int *)opt->value |= opt->defval;
		return 0;

	case OPTION_BOOLEAN:
		*(int *)opt->value = unset ? 0 : *(int *)opt->value + 1;
		return 0;

	case OPTION_SET_INT:
		*(int *)opt->value = unset ? 0 : opt->defval;
		return 0;

	case OPTION_SET_PTR:
		*(void **)opt->value = unset ? NULL : (void *)opt->defval;
		return 0;

	case OPTION_STRING:
		if (unset) {
			*(const char **)opt->value = NULL;
			return 0;
		}
		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-')) {
