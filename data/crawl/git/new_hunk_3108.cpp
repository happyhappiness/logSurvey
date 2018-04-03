			return opterror(opt, "expects a numerical value", flags);
		return 0;

	case OPTION_MAGNITUDE:
		if (unset) {
			*(unsigned long *)opt->value = 0;
			return 0;
		}
		if (opt->flags & PARSE_OPT_OPTARG && !p->opt) {
			*(unsigned long *)opt->value = opt->defval;
			return 0;
		}
		if (get_arg(p, opt, flags, &arg))
			return -1;
		if (!git_parse_ulong(arg, opt->value))
			return opterror(opt,
				"expects a non-negative integer value with an optional k/m/g suffix",
				flags);
		return 0;

	default:
		die("should not happen, someone must be hit on the forehead");
	}
