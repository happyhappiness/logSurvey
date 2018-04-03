	write_name(ce->name, ce_namelen(ce));
}

static int show_one_ru(struct string_list_item *item, void *cbdata)
{
	const char *path = item->string;
	struct resolve_undo_info *ui = item->util;
	int i, len;

	len = strlen(path);
	if (len < max_prefix_len)
		return 0; /* outside of the prefix */
	if (!match_pathspec(pathspec, path, len, max_prefix_len, ps_matched))
		return 0; /* uninterested */
	for (i = 0; i < 3; i++) {
		if (!ui->mode[i])
			continue;
		printf("%s%06o %s %d\t", tag_resolve_undo, ui->mode[i],
		       find_unique_abbrev(ui->sha1[i], abbrev),
		       i + 1);
		write_name(path, len);
	}
	return 0;
}

static void show_ru_info(void)
{
	if (!the_index.resolve_undo)
		return;
	for_each_string_list(the_index.resolve_undo, show_one_ru, NULL);
}

static void show_files(struct dir_struct *dir)
