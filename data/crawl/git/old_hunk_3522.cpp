		if (get_value(fn, data, var) < 0)
			break;
	}
	die("bad config file line %d in %s", cf->linenr, cf->name);
}

static int parse_unit_factor(const char *end, uintmax_t *val)
