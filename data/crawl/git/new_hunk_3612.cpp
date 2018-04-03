	return -1;
}

static void print_error_files(struct string_list *files_list,
			      const char *main_msg,
			      const char *hints_msg,
			      int *errs)
{
	if (files_list->nr) {
		int i;
		struct strbuf err_msg = STRBUF_INIT;

		strbuf_addstr(&err_msg, main_msg);
		for (i = 0; i < files_list->nr; i++)
			strbuf_addf(&err_msg,
				    "\n    %s",
				    files_list->items[i].string);
		strbuf_addstr(&err_msg, hints_msg);
		*errs = error("%s", err_msg.buf);
		strbuf_release(&err_msg);
	}
}

static int check_submodules_use_gitfiles(void)
{
	int i;
	int errs = 0;
	struct string_list files = STRING_LIST_INIT_NODUP;

	for (i = 0; i < list.nr; i++) {
		const char *name = list.entry[i].name;
