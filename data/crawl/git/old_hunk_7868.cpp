	case OPTION_CALLBACK:
		if (flags & OPT_UNSET)
			return (*opt->callback)(opt, NULL, 1);
		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-'))
			return (*opt->callback)(opt, NULL, 0);
		if (!arg)
