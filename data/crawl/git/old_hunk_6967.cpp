
static int show_all(void)
{
	struct path_list list = { NULL, 0, 0 };
	int result = for_each_remote(get_one_entry, &list);

	if (!result) {
		int i;

		sort_path_list(&list);
		for (i = 0; i < list.nr; i++) {
			struct path_list_item *item = list.items + i;
			printf("%s%s%s\n", item->path,
				verbose ? "\t" : "",
				verbose && item->util ?
					(const char *)item->util : "");
