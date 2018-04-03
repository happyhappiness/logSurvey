		return 0;

	case OPTION_CALLBACK:
		if (unset)
			return (*opt->callback)(opt, NULL, 1);
		if (opt->flags & PARSE_OPT_NOARG)
			return (*opt->callback)(opt, NULL, 0);
		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-'))
			return (*opt->callback)(opt, NULL, 0);
		if (!arg)
			return opterror(opt, "requires a value", flags);
		return (*opt->callback)(opt, get_arg(p), 0);

	case OPTION_INTEGER:
		if (unset) {
			*(int *)opt->value = 0;
			return 0;
		}
