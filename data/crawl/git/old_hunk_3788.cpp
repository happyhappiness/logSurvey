	}
}

int parse_range_arg(const char *arg, nth_line_fn_t nth_line_cb,
		    void *cb_data, long lines, long *begin, long *end)
{
	arg = parse_loc(arg, nth_line_cb, cb_data, lines, 1, begin);

	if (*arg == ',')
