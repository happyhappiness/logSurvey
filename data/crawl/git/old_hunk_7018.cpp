		return 0;

	case OPTION_STRING:
		if (unset) {
			*(const char **)opt->value = NULL;
			return 0;
		}
		if (opt->flags & PARSE_OPT_OPTARG && !p->opt) {
			*(const char **)opt->value = (const char *)opt->defval;
			return 0;
		}
		if (!arg)
			return opterror(opt, "requires a value", flags);
		*(const char **)opt->value = get_arg(p);
		return 0;

	case OPTION_CALLBACK:
