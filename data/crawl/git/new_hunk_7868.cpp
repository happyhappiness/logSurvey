	case OPTION_CALLBACK:
		if (flags & OPT_UNSET)
			return (*opt->callback)(opt, NULL, 1);
		if (opt->flags & PARSE_OPT_NOARG) {
			if (p->opt && !(flags & OPT_SHORT))
				return opterror(opt, "takes no value", flags);
			return (*opt->callback)(opt, NULL, 0);
		}
		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-'))
			return (*opt->callback)(opt, NULL, 0);
		if (!arg)
