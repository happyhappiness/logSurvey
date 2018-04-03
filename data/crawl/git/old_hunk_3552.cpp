	return ret;
}

static void interactive_main_loop(void)
{
	struct strbuf confirm = STRBUF_INIT;
	struct strbuf buf = STRBUF_INIT;
	struct string_list_item *item;
	const char *qname;

	while (del_list.nr) {
		putchar('\n');
		for_each_string_list_item(item, &del_list) {
			qname = quote_path_relative(item->string, NULL, &buf);
			printf(_(msg_would_remove), qname);
		}
		putchar('\n');

		printf(_("Remove [y/n]? "));
		if (strbuf_getline(&confirm, stdin, '\n') != EOF) {
			strbuf_trim(&confirm);
