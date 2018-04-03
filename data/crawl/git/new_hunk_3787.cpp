		cb_data.line_ends = ends;

		if (parse_range_arg(range_part, nth_line, &cb_data,
				    lines, &begin, &end,
				    spec->path))
			die("malformed -L argument '%s'", range_part);
		if (begin < 1)
			begin = 1;
