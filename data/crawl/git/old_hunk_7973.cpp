
static void show_stats(struct patch *patch)
{
	const char *prefix = "";
	char *name = patch->new_name;
	char *qname = NULL;
	int len, max, add, del, total;

	if (!name)
		name = patch->old_name;

	if (0 < (len = quote_c_style(name, NULL, NULL, 0))) {
		qname = xmalloc(len + 1);
		quote_c_style(name, qname, NULL, 0);
		name = qname;
	}

	/*
	 * "scale" the filename
	 */
	len = strlen(name);
	max = max_len;
	if (max > 50)
		max = 50;
	if (len > max) {
		char *slash;
		prefix = "...";
		max -= 3;
		name += len - max;
		slash = strchr(name, '/');
		if (slash)
			name = slash;
	}
	len = max;

	/*
	 * scale the add/delete
	 */
	max = max_change;
	if (max + len > 70)
		max = 70 - len;

	add = patch->lines_added;
	del = patch->lines_deleted;
	total = add + del;

	if (max_change > 0) {
		total = (total * max + max_change / 2) / max_change;
		add = (add * max + max_change / 2) / max_change;
		del = total - add;
	}
	if (patch->is_binary)
		printf(" %s%-*s |  Bin\n", prefix, len, name);
	else
		printf(" %s%-*s |%5d %.*s%.*s\n", prefix,
		       len, name, patch->lines_added + patch->lines_deleted,
		       add, pluses, del, minuses);
	free(qname);
}

static int read_old_data(struct stat *st, const char *path, struct strbuf *buf)
