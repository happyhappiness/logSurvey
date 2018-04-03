
	while (del_list.nr) {
		putchar('\n');
		printf_ln(Q_("Would remove the following item:",
			     "Would remove the following items:",
			     del_list.nr));
		putchar('\n');

		pretty_print_dels();

		printf(_("Remove [y/n]? "));
		if (strbuf_getline(&confirm, stdin, '\n') != EOF) {
			strbuf_trim(&confirm);
		} else {