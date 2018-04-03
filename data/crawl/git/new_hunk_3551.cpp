
	while (del_list.nr) {
		putchar('\n');
		clean_print_color(CLEAN_COLOR_HEADER);
		printf_ln(Q_("Would remove the following item:",
			     "Would remove the following items:",
			     del_list.nr));
		clean_print_color(CLEAN_COLOR_RESET);
		putchar('\n');

		pretty_print_dels();

		clean_print_color(CLEAN_COLOR_PROMPT);
		printf(_("Remove [y/n]? "));
		clean_print_color(CLEAN_COLOR_RESET);
		if (strbuf_getline(&confirm, stdin, '\n') != EOF) {
			strbuf_trim(&confirm);
		} else {