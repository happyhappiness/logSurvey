			*(const char **)opt->value = (const char *)NULL;
			return 0;
		}
		if (!p->opt && p->argc <= 1)
			return opterror(opt, "requires a value", flags);
		*(const char **)opt->value = get_arg(p);
		return 0;

	case OPTION_INTEGER:
		if (flags & OPT_UNSET) {
			*(int *)opt->value = 0;
			return 0;
		}
		if (!p->opt && p->argc <= 1)
			return opterror(opt, "requires a value", flags);
		*(int *)opt->value = strtol(get_arg(p), (char **)&s, 10);
		if (*s)
