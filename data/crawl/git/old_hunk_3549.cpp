	copts.indent = "  ";
	copts.padding = 2;
	print_columns(&list, colopts, &copts);
	putchar('\n');
	strbuf_release(&buf);
	string_list_clear(&list, 0);
}

static void interactive_main_loop(void)
{
	struct strbuf confirm = STRBUF_INIT;

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
			/* Ctrl-D is the same as "quit" */
			string_list_clear(&del_list, 0);
			putchar('\n');
			printf_ln("Bye.");
			break;
		}

		if (confirm.len) {
			if (!strncasecmp(confirm.buf, "yes", confirm.len)) {
				break;
			} else if (!strncasecmp(confirm.buf, "no", confirm.len) ||
				   !strncasecmp(confirm.buf, "quit", confirm.len)) {
				string_list_clear(&del_list, 0);
				printf_ln("Bye.");
				break;
			} else {
				continue;
			}
		}
	}

	strbuf_release(&confirm);
}

int cmd_clean(int argc, const char **argv, const char *prefix)