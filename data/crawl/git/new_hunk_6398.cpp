	ar_args->time = archive_time;
}

#define OPT__COMPR(s, v, h, p) \
	{ OPTION_SET_INT, (s), NULL, (v), NULL, (h), \
	  PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, (p) }
