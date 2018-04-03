		color_parse(def_color, "command line", parsed_color);

	fputs(parsed_color, stdout);
	return 0;
}

static int stdout_is_tty;
