
static struct path_list mailmap = {NULL, 0, 0, 0};

static void insert_one_record(struct path_list *list,
			      const char *author,
			      const char *oneline)
{
	const char *dot3 = common_repo_prefix;
	char *buffer, *p;
	struct path_list_item *item;
	struct path_list *onelines;
	char namebuf[1024];
	size_t len;
	const char *eol;
	const char *boemail, *eoemail;

	boemail = strchr(author, '<');
	if (!boemail)
		return;
	eoemail = strchr(boemail, '>');
	if (!eoemail)
		return;
	if (!map_email(&mailmap, boemail+1, namebuf, sizeof(namebuf))) {
		while (author < boemail && isspace(*author))
			author++;
		for (len = 0;
		     len < sizeof(namebuf) - 1 && author + len < boemail;
		     len++)
			namebuf[len] = author[len];
		while (0 < len && isspace(namebuf[len-1]))
			len--;
		namebuf[len] = '\0';
	}

	buffer = xstrdup(namebuf);
	item = path_list_insert(buffer, list);
	if (item->util == NULL)
		item->util = xcalloc(1, sizeof(struct path_list));
	else
		free(buffer);

	eol = strchr(oneline, '\n');
	if (!eol)
		eol = oneline + strlen(oneline);
	while (*oneline && isspace(*oneline) && *oneline != '\n')
		oneline++;
	if (!prefixcmp(oneline, "[PATCH")) {
		char *eob = strchr(oneline, ']');
		if (eob && (!eol || eob < eol))
			oneline = eob + 1;
	}
	while (*oneline && isspace(*oneline) && *oneline != '\n')
		oneline++;
	len = eol - oneline;
	while (len && isspace(oneline[len-1]))
		len--;
	buffer = xmemdupz(oneline, len);

	if (dot3) {
		int dot3len = strlen(dot3);
