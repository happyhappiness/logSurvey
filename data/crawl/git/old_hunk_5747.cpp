			continue;

		pos = fprintf(stderr, "    ");
		if (opts->short_name) {
			if (opts->flags & PARSE_OPT_NODASH)
				pos += fprintf(stderr, "%c", opts->short_name);
			else
