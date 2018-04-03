		}
		return get_value(p, options, flags);
	}
	if (abbrev_option)
		return get_value(p, abbrev_option, abbrev_flags);
	return error("unknown option `%s'", arg);
