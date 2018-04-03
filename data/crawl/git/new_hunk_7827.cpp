		}
		return get_value(p, options, flags);
	}

	if (ambiguous_option)
		return error("Ambiguous option: %s "
			"(could be --%s%s or --%s%s)",
			arg,
			(ambiguous_flags & OPT_UNSET) ?  "no-" : "",
			ambiguous_option->long_name,
			(abbrev_flags & OPT_UNSET) ?  "no-" : "",
			abbrev_option->long_name);
	if (abbrev_option)
		return get_value(p, abbrev_option, abbrev_flags);
	return error("unknown option `%s'", arg);
