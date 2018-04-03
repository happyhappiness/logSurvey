
static struct path_list mailmap = {NULL, 0, 0, 0};

static void insert_author_oneline(struct path_list *list,
		const char *author, int authorlen,
		const char *oneline, int onelinelen)
{
	const char *dot3 = common_repo_prefix;
	char *buffer, *p;
	struct path_list_item *item;
	struct path_list *onelines;

	while (authorlen > 0 && isspace(author[authorlen - 1]))
		authorlen--;

	buffer = xmemdupz(author, authorlen);
	item = path_list_insert(buffer, list);
	if (item->util == NULL)
		item->util = xcalloc(1, sizeof(struct path_list));
	else
		free(buffer);

	if (!prefixcmp(oneline, "[PATCH")) {
		char *eob = strchr(oneline, ']');

		if (eob) {
			while (isspace(eob[1]) && eob[1] != '\n')
				eob++;
			if (eob - oneline < onelinelen) {
				onelinelen -= eob - oneline;
				oneline = eob;
			}
		}
	}

	while (onelinelen > 0 && isspace(oneline[0])) {
		oneline++;
		onelinelen--;
	}
	while (onelinelen > 0 && isspace(oneline[onelinelen - 1]))
		onelinelen--;
	buffer = xmemdupz(oneline, onelinelen);

	if (dot3) {
		int dot3len = strlen(dot3);
