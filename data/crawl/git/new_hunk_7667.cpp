	printf("%s", reset);
}

static void fill_print_name(struct diffstat_file *file)
{
	char *pname;

	if (file->print_name)
		return;

	if (!file->is_renamed) {
		struct strbuf buf;
		strbuf_init(&buf, 0);
		if (quote_c_style(file->name, &buf, NULL, 0)) {
			pname = strbuf_detach(&buf, NULL);
		} else {
			pname = file->name;
			strbuf_release(&buf);
		}
	} else {
		pname = pprint_rename(file->from_name, file->name);
	}
	file->print_name = pname;
}

static void show_stats(struct diffstat_t* data, struct diff_options *options)
{
	int i, len, add, del, total, adds = 0, dels = 0;
