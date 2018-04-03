			return (*opt->callback)(opt, NULL, 0) ? (-1) : 0;
		if (opt->flags & PARSE_OPT_OPTARG && !p->opt)
			return (*opt->callback)(opt, NULL, 0) ? (-1) : 0;
		if (!arg)
			return opterror(opt, "requires a value", flags);
		return (*opt->callback)(opt, get_arg(p), 0) ? (-1) : 0;

	case OPTION_INTEGER:
		if (unset) {
